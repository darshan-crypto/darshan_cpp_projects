#include<asio.hpp>
#include<iostream>
#include"netlib/tcp.h"
#include<thread>
using namespace std;
void waithandler(error e){
    cout << "a" <<e.message();
} 
int main(){
    
tcp::server s("127.0.0.1",8080);
s.accept();
//s.socket->async_wait(s.socket->wait_write,  [](const asio::error_code ec){cout << "x";});
//s.socket->async_write_some(asio::buffer("shl"),  [](const asio::error_code& ec,size_t x){cout << "x";});

s.async_wait_for_write(&waithandler);
this_thread::sleep_for(chrono::seconds(5));


}