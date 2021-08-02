
#include<asio.hpp>
#include<iostream>
#include"netlib/http_header.h"
using namespace std;
int main(int argc, char const *argv[])
{
 enum HTTP_METHODS M,v;

M=GET;
v = POST;
enum HTTP_VERSION s;
s = HTTP2;
http_header::request_header::header_builder::request_builder b(M,"itc.html",s);
cout << b.getheader();
b.setmethod(v);
b.sethttpversion(HTTP1);
b.setpath("ok inserting dk  path");
cout << b.getheader();
// std::string s = "hello";
// s.insert(1,"s");
// cout << s;
    return 0;
}
