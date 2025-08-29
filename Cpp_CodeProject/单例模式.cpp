#include <iostream>
#include <mutex>
// 单例模式：构造函数私有化，禁用拷贝构造和赋值运算，并对外提供一个接口

// 懒汉式，线程安全
class LazySingleton {
public:
    //获取唯一实例，static表示静态成员函数，不依赖类的对象即可调用该函数
    static LazySingleton* getInstance(){
        // static 表示只在第一次调用时创建instance
        static LazySingleton* instance;  
        return instance;
    }
private:
      // 私有构造函数，防止外部创建对象
    LazySingleton(){
        std::cout << "调用构造函数"<<std::endl;
    }    
    // 禁用拷贝构造和赋值运算符
    LazySingleton(const LazySingleton&) = delete;
    LazySingleton& operator=(const LazySingleton&) = delete;
};

// 饿汉模式：不管用不用得到，都构造出来，本身就是线程安全的
class hungrySingleton{
public:
    static hungrySingleton* getinstance(){
        return instance;
    }
private:
    // 单例为静态成员变量，类内声明，类外初始化
    static hungrySingleton* instance;
    hungrySingleton() {
        std::cout << "饿汉模式构造函数" << std::endl;
    }
};
// 静态变量，类内声明，类外初始化
hungrySingleton* hungrySingleton::instance = new hungrySingleton;

int main()
{
    LazySingleton*  lazy = LazySingleton::getInstance();
    hungrySingleton* hungry = hungrySingleton::getinstance();
    
}

class Single{
public:
    static Single* getInstance(){
        static Single* sing;
        return sing;
    }
private:
    Single(){
        std::cout << "调用构造函数" << std::endl;
    }
    Single(const Single&) = delete;
    Single& operator=(const Single&) = delete;
};

