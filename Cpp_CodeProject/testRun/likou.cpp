#include <iostream>
#include <thread>

using namespace std;

// 一个简单的函数，作为线程的入口函数
void foo(int Z) {
    for (int i = 0; i < Z; i++) {
        cout << "线程使用函数指针作为可调用参数\n";
    }
}

// 可调用对象的类定义
class ThreadObj {
public:
    void operator()(int x) const {
        for (int i = 0; i < x; i++) {
            cout << "线程使用函数对象作为可调用参数\n";
        }
    }
};

int main()
{
    //使用函数指针创建线程
    thread th1(foo, 3);
    //使用函数对象创建线程
    thread th2(ThreadObj(), 3);
    //使用lambda表达式创建线程
    thread th3([](int x){
        for(int i = 0; i < x; i++){
            cout << "线程使用lambda表达式可作为调用参数\n";
        }
    }, 4);

    //等待所有线程完成
    th1.join();
    th2.join();
    th3.join();
    return 0;
}