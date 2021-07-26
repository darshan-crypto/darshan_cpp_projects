#include<iostream>
#include<thread>
#include<asio.hpp>
#include"netlib/tcp.h"

using namespace std;
int main(){

     tcp::server server("127.0.0.1",8089);
 
    server.accept();
  
//     std::string s;
//   //  server.read_some(&s,500);
//     std::cout << s.data();
//     server.waitforwrite();
//     server.write_some("<html> <head  />hello <body></body></html>");
// //std::this_thread::sleep_for(std::chrono::seconds(10));

//     server.write_some("<html> <head  />hello6 <body></body></html>");
// server.write_some("\b\b\b\b\b\b");
//     server.close();
//tcp::client client("172.217.166.36",443);
//client.connect();
//client.waitforwrite();
//http_header::request_header::header_builder::request_builder h(GET,"",HTTP1);
//h.set("Host","www.example.com");
//h.set("Accept","text/html");
//h.set("Connection","close");

//h.finish();
//cout << h.getheader();
/*
const char * h = "GET / HTTP/2 \r\n"
"Host: www.google.com \r\n"
"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*///*;q=0.8 \r\n"
//"Connection: keep-alive \r\n\r\n";
///lient.write_some(h);
/*cli//ent.waitforread();
cout << client.avalible();
std::string r;
client.read_some(&r,client.avalible());
cout << r; */
}
