#include<iostream>
#include<string>
using namespace std;
int main(int argc, char const *argv[])
{
    std::string str = "get /index.html HTTP/2 \r\n connection :close \r\n";
    std::string v;
    int i =0;
    while(str.at(i) != '\r'){
    //    cout << str.at(i);
        v+=str.at(i);
        i++;
    }
cout << v;
    return 0;
}
