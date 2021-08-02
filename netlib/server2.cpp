#include<asio.hpp>
#include<iostream>
#include"netlib/tcp.h"
#include<thread>
using namespace std;
int main(int argc, char const *argv[])
{
    asio::io_context io_context;
      asio::ip::address a4;
    
    a4.from_string("127.0.0.1");
    asio::ip::tcp::acceptor a(io_context,asio::ip::tcp::endpoint(a4,8080));
    
    asio::ip::tcp::socket s(io_context);
    io_context.run();
    a.accept(s);
    s.async_wait(a.wait_write,[](const asio::error_code &ec){cout << "s";exit (1);});
     this_thread::sleep_for(chrono::seconds(5));
    s.write_some(asio::buffer("hello")); 
    return 0;
}
