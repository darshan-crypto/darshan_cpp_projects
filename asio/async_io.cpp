#include<iostream>
#include<asio.hpp>
char header[] =
         "GET / HTTP/1.1 \r\n"
        "Host: example.com \r\n"
         "Connection : keep-alive \r\n"
        "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:86.0) Gecko/20100101 Firefox/86.0\r\n"
       
        "Accept : text/html \r\n\r\n";

int main(int argc, char const *argv[])
{
    asio::io_context i;
    asio::ip::tcp::resolver resolver(i);
    asio::ip::tcp::resolver::results_type result = resolver.resolve("www.example.com","http");
    asio::ip::tcp::socket socket(i);
    asio::connect(socket,result);    
    if (socket.is_open())
    {
      socket.wait(socket.wait_write);
      socket.write_some(asio::buffer(header,sizeof(header)));
      socket.async_wait(socket.wait_read,[&](asio::error_code ec){
std::cout << ec.message()<< "no error";
exit(2);
      });



    }
    
    return 0;
}
