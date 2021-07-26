#include<iostream>
#include<thread>
using namespace std;
#include<mutex>
class t2
{
private:
    /* data */
public:
    t2(/* args */);
    void start();
    void threadss(int);
    int x=909;
    mutex m;

};

t2::t2(/* args */)
{
}
void t2::start(){

for(int i=0;i<5000;i++){
thread t1(&t2::threadss,this,i);
t1.detach();
}
}
void t2::threadss(int i){
m.lock();
x=i;

printf("%d",x);
m.unlock();
}









int main(){

t2 r;
r.start();


    return 0;
}