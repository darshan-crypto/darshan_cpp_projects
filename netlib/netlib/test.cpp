#include<iostream>
#include"webserver.h"
using namespace std;
int main(){

//    openssl::server server("localhost",80);
//  server.accept();
// char read[10000]; 
// int x = server.read_some(read,10000);
char *readed ="GET / HTTP/1.1 \r\n"
 
"Connection: keep-alive \r\n"
"Upgrade-Insecure-Requests: 1\r\n\r\n";
webserver webserver("127.0.0.1",443);
webserver.onrequest("/","index.html",HTML_FILE);
webserver.onrequest("/m.css","m.css",HTML_FILE);
webserver.onrequest("/darshan","<h1>darshan</h1>",TEXT);
webserver.onrequest("/button","<h1>ss</h1><button>click</button>",TEXT);
webserver.onrequest("/avp","avp.html",HTML_FILE);
webserver.onrequest("/vue","<script src=\"/v.js\"></script>",TEXT);
webserver.onrequest("/favicon.ico","n.png",HTML_FILE);
webserver.onrequest("/v.js","v.js",HTML_FILE);
webserver.onrequest("/.well-known/pki-validation/9EA22CF91D23A9B7EC5094EB01597199.txt","9EA22CF91D23A9B7EC5094EB01597199.txt",HTML_FILE);
webserver.onrequest("/download","download.html",HTML_FILE);
webserver.onrequest("/downloadm","n.png",HTML_FILE);
// ssl ssl(*webserver.server);



webserver.ondefaultrequest("x.html",HTML_FILE);
webserver.start();
//  http_header::request_header::request_parser  *req = new http_header::request_header::request_parser(std::string(readed,strlen(readed)));

// printf("%s",req->getpath().c_str());
// for(int i=0;i<x;i++){
//   printf("%c",read[i]);
// }
// printf("%d",x);
// string s = "HTTP/1.1 302 Moved Permanently\r\nLocation:https://google.com\r\n\r\n";
// server.write_some((char*)s.c_str(),s.length());
//server.write_some("</h1><h2>heelo2</h2></body></html>",19); 

    return 0;
}