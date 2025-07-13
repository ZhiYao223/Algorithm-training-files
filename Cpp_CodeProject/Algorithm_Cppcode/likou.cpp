#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/platform_device.h>
#include <linux/ioport.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/of_irq.h>
#include <linux/interrupt.h>

#define DEVICE_NAME "taxue, home_key"


int home_gpio_idx;
int home_inter_idx;

static irqreturn_t home_interrupt(int irq, void* dev_id){
	printk("HOME KEY PRESSED!\n");
	return IRQ_HANDLED;
}

int drProbe(struct platform_device* pdev){
	int ret;
	struct device_node *np; //�豸���ڵ�ָ��
	np = pdev->dev.of_node;
	if (!np){
		printk("No device tree node found\n");
		return -ENODEV;
	}
	// //���ݽڵ��inter_gpio���ԣ���ȡgpio���
	home_gpio_idx = of_get_named_gpio(np, "inter_gpio", 0);
	//���벢����GPIO
	ret = devm_gpio_request(&pdev->dev, home_gpio_idx, "home_key");
	gpio_direction_input(home_gpio_idx);
	//��ȡ�жϺ�
	home_inter_idx = gpio_to_irq(home_gpio_idx);
	// ע���жϴ������
	ret = devm_request_irq(&pdev->dev, home_inter_idx, home_interrupt, IRQF_TRIGGER_FALLING, "home_key", pdev);
	return 0
}



static const strcut of_device_id home_key_match[] = {
	{.compatible = DEVICE_NAME},
	{}
};

int drRemove(struct platform_device *dev){
	free_irq(home_inter_idx, dev); //�ͷ��ж�
	gpio_free(home_gpio_idx); //�ͷ�gpio
	printk("driver remove\n");
	return 0;
}
MOUDLE_DEVICE_TABLE(of, home_key_match);

static struct platform_driver home_key_driver = {
	.probe = drProbe,
	.remove = drRemove,
	.driver = {
		.name = "home-key-driver",
		.owner = THIS_MODULE,
		.of_match_table = home_key_match,
	}
};
// ��ģ��ע��
module_platform_driver(home_key_driver);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("TAXUE");

