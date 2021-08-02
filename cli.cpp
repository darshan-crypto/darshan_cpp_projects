#include<iostream>
#include"tcp.h"
#include<chrono>
#include<thread>
void x(const  asio::error_code ec){
    std::cout<< "ss";

};
int main(){
tcp::client c("192.168.43.204",4444);
c.connect();

std::string t;
c.async_wait_for_read(x);
std::cout << c.avalible();
int vd = c.read_some(&t,5);
std::cout << t<<vd;
	}