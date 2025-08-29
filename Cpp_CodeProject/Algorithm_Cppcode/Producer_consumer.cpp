#include <iostream>
#include <atomic>
#include <vector>
#include <mutex>
#include <thread>
#include <queue>
#include <chrono>
#include <thread>
#include <condition_variable>
using namespace std;
std::mutex mtx; //互斥锁，用于保护共享资源
std::condition_variable cv_produce; // 用于生产者的条件变量
std::condition_variable cv_consume; // 用于消费者的条件变量

std::queue<int> buffer; // 缓冲区
const int BUFFER_SIZE = 5; // 缓冲区大小

// 生产者线程
void producer(int id){
    int item = 0;
    while (true){
        std::unique_lock<std::mutex> lock(mtx);  // 加锁
        // 如果缓冲区已满，则等待消费者消费
        cv_produce.wait(lock, []{return buffer.size() < BUFFER_SIZE;});
        // 将生产的物品放入缓冲区
        buffer.push(item);
        cout << "生产者" << id << "生产产品：" << item << endl;
        item++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        //通知消费者可以消费了
        cv_consume.notify_one(); 
    }
}
// 消费者线程
void consumer(int id){
   while (true){
        std::unique_lock<std::mutex> lock(mtx); // 加锁
        cv_consume.wait(lock, []{return !buffer.empty();}); // 如果缓冲区为空，则等待生产者生产产品
        if (buffer.empty()) break;
        int item = buffer.front();
        buffer.pop();
        cout << "消费者" << id << "消费产品：" << item << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cv_produce.notify_one();  // 通知生产者可以继续生产
   } 
}

int main()
{
    const int num_producers = 1;
    const int num_consumers = 1;
    vector<thread> producers;
    vector<thread> consumers;

    
    // 创建生产者线程
    for (int i = 1; i <= num_producers; i++){
        producers.push_back(thread(producer, i));
    }
    // 创建消费者线程
    for (int i = 1; i <= num_consumers; i++){
        consumers.push_back(thread(consumer, i));
    }
    // 等待所有线程完成
    for (auto  &th : producers){
        th.join();
    }
    for (auto &th : consumers){
        th.join();
    }
    return 0;
}



// double division(int a, int b){
//     if (b == 0){
//         throw "Division by zero condition!";
//     }
//     return (a/b);
// }
// int main()
// {
//     int x = 10;
//     int y = 0;
//     double z = 0;
//     try{
//         z = division(x, y);
//         cout << z << endl;
//     }catch(const char* mesg){
//         cerr<< mesg << endl;
//     }
//     return 0;
// }





// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <stdlib.h>
// #include <unistd.h>
// #include <chrono>
// #include <condition_variable>
// #include <atomic>
// #include <vector>
// using namespace std;

// std::mutex mtx; 
// std::condition_variable cv; // 条件变量，用于线程同步
// bool ready = false; //线程执行的标志
// int order = 0; // 用于控制线程的执行顺序

// // 线程1
// void safeFunction1(int num)
// {
//     std::this_thread::sleep_for(std::chrono::seconds(1)); //延迟1s
//     for (int i = 0; i < num; i++){
//         cout << "安全访问共享资源1\n"<< std::flush;
//         std::this_thread::sleep_for(std::chrono::seconds(1)); //延迟1s
//     }
//     cout << "safeFunctino1 线程完成"<< endl;
//     // 线程1完成任务后，通知线程2
//     {
//         std::lock_guard<std::mutex> lock(mtx); //加锁保护共享资源
//         ready = true;
//     }
//     cv.notify_one(); // 通知线程2
// }
// // 线程2
// void safeFunction2(int num)
// {
//     cout << "线程2等待线程1完成...."<<endl;
//     // 等待线程1完成任务
//     std::unique_lock<std::mutex> lock(mtx);
//     cv.wait(lock, []{return ready;}); // 等待条件为true
//     cout << "线程2任务开始："<< endl;
//     for (int i = 0; i < num; i++){
//         cout << "安全访问共享资源2\n"<< std::flush;
//         std::this_thread::sleep_for(std::chrono::seconds(1));  // 延迟2秒
//     }
//     cout << "线程2任务结束！"<< endl;
// }

// void thread1()
// {
//     std::this_thread::sleep_for(std::chrono::seconds(5));  // 延迟2秒
//     cout << "线程1 完成" << endl;
//     // 线程1完成后，通知线程2
//     lock_guard<mutex> lock1(mtx); // 加锁保护共享资源
//     ready = true;
//     cv.notify_one(); // 通知线程2
// }
// void thread2()
// {
//     this_thread::sleep_for(chrono::seconds(1));
//     cout << "线程2等待线程1完成..."<<endl;
//     //等待线程1完成任务
//     unique_lock<mutex> lock2(mtx); // 加锁并可以使用条件变量
//     cv.wait(lock2, []{return ready;});
//     cout << "线程2开始" << endl;
// }

// void printA(){
//     std::unique_lock<std::mutex> lock(mtx);
//     cv.wait(lock, []{return order == 0;}); // count=0，线程A才能执行
//     cout << "线程A执行开始" << endl;
//     std::this_thread::sleep_for(std::chrono::seconds(3));
//     cout << "线程A执行结束" << endl;
//     order = 1; // 线程A执行完后，修改count，通知线程B
//     cv.notify_all(); // 通知线程B
// }
// void printB(){
//     std::unique_lock<std::mutex> lock(mtx);
//     cv.wait(lock, []{return order == 1;}); // count=1,线程B才能执行
//     cout << "线程B执行开始" << endl;
//     std::this_thread::sleep_for(std::chrono::seconds(3));
//     cout << "线程B执行结束" << endl;
//     order = 2; // 线程B执行完后，修改count， 通知线程C
//     cv.notify_all(); // 通知线程C
// }
// void printC(){
//     std::unique_lock<std::mutex> lock(mtx);
//     cv.wait(lock, []{return order == 2;}); // count=2，线程C才能执行
//     cout << "线程C执行开始" << endl;
//     std::this_thread::sleep_for(std::chrono::seconds(3));
//     cout << "线程C执行结束" << endl;
//     order = 0;  // 线程C执行完后，修改count， 通知线程A
//     cv.notify_all(); // 通知线程A
// }
// // 创建一个原子计数器
// std::atomic<int> counter(0);
// void incrementCounter(){
//     for (int i = 0; i < 1000; i++){
//         counter++; // 原子操作，自增
//     }
// }


// int main()
// {
//     // thread th1(thread1);
//     // thread th2(thread2);
//     thread tA(printA);
//     thread tB(printB);
//     thread tC(printC);
//     vector<std::thread> threads;
//     // 创建多个线程来并行增大计数器
//     for (int i = 0; i < 10; i++){
//         threads.push_back(std::thread(incrementCounter));
//     }
//     for (auto& th : threads){
//         th.join();
//     }
//     std::cout << "最终计数器值："<< counter.load() << std::endl;
//     // thread th4(safeFunction1, 5);
//     // thread th5(safeFunction2, 5);
//     //等待所有线程完成
//     // th1.join();
//     // th2.join();
//     tA.join();
//     tB.join();
//     tC.join();
//     return 0;
// }

