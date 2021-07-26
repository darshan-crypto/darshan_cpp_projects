#include<iostream>
using namespace std;
#include<openssl/bio.h>

int main(){
   BIO *b =BIO_new_connect("127.0.0.1:8089");
   if(BIO_do_connect(b) <=0)printf("error");
   char m[200];
   BIO_read(b,m,200);
   printf("%s",m);
    return 0;
}