#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
mutex m,m1;
timed_mutex m5;
int z = 0;
void n1(){
    
    while (1)
    {
        /* code */
    
    
    if (m5.try_lock_until(chrono::steady_clock::now() + chrono::seconds(3)));
    {
        z++;
        this_thread::sleep_for(chrono::seconds(5));
     //   m5.unlock();
    break;
    }
    }
}
void n2(){
       while (1)
    {
        /* code */
    
    
    if (m5.try_lock_until(chrono::steady_clock::now() + chrono::seconds(3)));
    {
        z++;
        this_thread::sleep_for(chrono::seconds(5));
       // m5.unlock();
    break;
    }
    }
    }

int main(int argc, char const *argv[])
{
    thread t1(n1);
    thread t2(n2);

    t1.join();   
    t2.join();
  // n1();
   //n2();
    cout << z;
    return 0;
}
