#include<iostream>
#include"netlib/http_header.h"
using namespace std;
int main(int argc, char const *argv[])
{
http_header::request_header::request_builder r(HTTP_METHODS::GET,"mvsnmam?dhs.html",HTTP_VERSION::HTTP2);    
r.set("Connection","close");
//cout <<r.build();

std::string s = "GET /hellophttpget1.1darshanderivation.html HTTP/2\r\n Connection : closec\r\nHost :snippets.google.com\r\naccept :sd\r\n\r\n";
 http_header::request_header::request_parser r7(s);
// cout << r7.getmainline().data();
cout << r7.get("Connection");
;    return 0;
}

