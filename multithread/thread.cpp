#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
int v = 0;
void n1(){
    
    v++;
}
int main(int argc, char const *argv[])
{
    thread t1(n1);
    thread t2(n1);
thread::native_handle_type i  = t1.native_handle();
    cout << i;
    
t1.join();

t2.join();


    return 0;
}
