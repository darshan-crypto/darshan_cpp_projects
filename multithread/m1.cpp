#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
unsigned long long  eki,beki;
void task(int x, int y ){
for(int i = x;i<y;i++)
{if(i%2==1) eki+=i;}
}
void task2(int x, int y ){
for(int i = x;i<y ;i++)
{if(i%2==0) beki+=i;}
}
int main(int argc, char const *argv[])
{
    auto starttime = chrono::high_resolution_clock::now();
     thread t1(task,0,190000000);

     thread t2(task2,0,190000000);
   //  t1.join();
    // t2.join();
    t1.detach();
    t2.detach();
    task(0,1900000000);
    task2(0,1900000000);
       auto endtime = chrono::high_resolution_clock::now();
       std::chrono::seconds duretion = chrono::duration_cast<chrono::seconds>(endtime-starttime);
   cout << duretion.count();
   cout <<"\n"<< eki<<"\n"<<beki;
    return 0;
}

