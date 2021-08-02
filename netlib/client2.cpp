#include<iostream>
#include<asio.hpp>
#include<thread>
using namespace std;
void waithan(const asio::error_code &)
{
    std::cout << "vlsdssd";
    exit(90);
    system("ls");
  }
int main(){
char h[] = "GET / HTTP/2 \r\n"
"Host: www.boost.org \r\n"
"User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:87.0) Gecko/20100101 Firefox/87.0\r\n"
"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
"Accept-Language: en-US,en;q=0.5 \r\n"
"Accept-Encoding: gzip, deflate, br \r\n"
"Connection: keep-alive \r\n"

"Cache-Control: max-age=0 \r\n\r\n";
asio::io_context iocontext;
asio::error_code ec;
//iocontext.run(ec);
    asio::ip::tcp::resolver r(iocontext);
asio::ip::tcp::resolver::results_type a= r.resolve("146.20.110.251","443");

asio::ip::tcp::socket s(iocontext);
asio::connect(s,a);
if (s.is_open())
{
    cout << "connection open" <<ec.message();

 //   s.async_wait(s.wait_write,&waithan);
   s.wait(s.wait_write);
    s.write_some(asio::buffer(h))
; //   s.async_wait(s.wait_read,&waithan);
   // iocontext.run();
  s.wait(s.wait_read);
char c[2000];
  int x = s.read_some(asio::buffer(c));
  //  iocontext.restart();
    //iocontext.run();
int i=0;
while(i<x){cout << c[i];i++;}
}



}
