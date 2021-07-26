#include<stdio.h>
#include<openssl/bio.h>
#include<openssl/err.h>
#include<arpa/inet.h>
#include<sys/socket.h>
int main()
{

BIO_ADDRINFO *in;
    struct in_addr x;
    x.s_addr=inet_addr("127.0.0.1");
 BIO_lookup_ex("127.0.0.1","8089",BIO_LOOKUP_CLIENT,AF_INET,SOCK_STREAM,IPPROTO_TCP,&in);
 BIO_ADDR *ad= BIO_ADDR_new();

BIO_ADDR *peer= BIO_ADDR_new();
BIO_ADDR_rawmake(ad,AF_INET,&x,sizeof(x),803);
int x1 =BIO_socket(AF_INET,SOCK_STREAM,0,0);
if (x1<=0)
{
    /* code */
    printf("error");
}
printf("%d",x1);
int vb =BIO_bind(x1,BIO_ADDRINFO_address(in),BIO_SOCK_REUSEADDR);
  int xn= BIO_listen(x1,ad,0);
    printf(" \n%s %d %%d",ERR_error_string(ERR_get_error(),0),vb);

 int v=  BIO_accept_ex(x1,peer,0);
    printf(" %s %d %%d",ERR_error_string(ERR_get_error(),0),vb);
   BIO_closesocket(x1);
    return 0;
}