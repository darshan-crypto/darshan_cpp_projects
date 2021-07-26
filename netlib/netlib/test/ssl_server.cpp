#include<openssl/bio.h>
#include<stdio.h>
#include<openssl/ssl.h>
#include<openssl/err.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){

    int server;
    SSL_CTX *ctx;
    SSL *ssl;

    ctx = SSL_CTX_new(SSLv23_method());
   if(  SSL_CTX_use_certificate_file(ctx,"server.crt",SSL_FILETYPE_PEM)<=0)printf("error");
     if(  SSL_CTX_use_PrivateKey_file(ctx,"serverkey.key",SSL_FILETYPE_PEM)<=0)printf("error");
    if(!SSL_CTX_check_private_key(ctx))printf("error 3");
    
    server = socket(AF_INET,SOCK_STREAM,0);
     struct sockaddr_in in,in2;
    in.sin_family=AF_INET;
    in.sin_addr.s_addr=inet_addr("127.0.0.1");
    in.sin_port= htons(8089);
socklen_t v= sizeof(in2);
    bind(server,(struct sockaddr*)&in,sizeof(in));
    listen(server,10);
   int x= accept(server,(struct sockaddr*)&in2,&v);

ssl = SSL_new(ctx);
SSL_set_fd(ssl,x);
SSL_accept(ssl);
char bu[1000];
SSL_read(ssl,bu,1000);
printf("\n %s",bu);
    return 0;
}
