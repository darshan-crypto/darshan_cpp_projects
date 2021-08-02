#include<asio.hpp>
#include"netlib/tcp.h"
#include<iostream>

using namespace std;
int main(){

tcp::client c("127.0.0.1",8080);
c.connect();
string s;
c.waitforread();
c.read_some(&s,5);
cout << s;



}