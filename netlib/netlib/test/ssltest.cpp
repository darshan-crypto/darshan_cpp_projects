
#include"ssl.h"
using namespace std;
int main(){


// char *readed ="GET / HTTP/1.1 \r\n"
 
// "Connection: keep-alive \r\n"
// "Upgrade-Insecure-Requests: 1\r\n\r\n";
// socketserver::server s("192.168.43.204",443,10);
// webserver webserver("127.0.0.1",443);

// s.bindconnection();
// s.acceptconnection();

ssl sslt("127.0.0.1",8089,10);

char m[200];
sslt.bindconnection();
while(1){
sslt.acceptconnection();
// sslt.bindconnection();
// sslt.acceptconnection();
int x=sslt.read_some(m,200);
printf("%s readded %d %s \n",m,x,ERR_error_string(ERR_get_error(),0));


sslt.closepeer();
}// }
return 0;
}