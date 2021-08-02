#include<iostream>
using namespace std;
void c(int c){
    cout << "d" << c;
}
void n(void m(int )){
    cout << "s";
    m(1);
}


int main(int argc, char const *argv[])
{
    n(c);
    return 0;
}
