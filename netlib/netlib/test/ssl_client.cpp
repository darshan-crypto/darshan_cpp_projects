#include<openssl/bio.h>
#include<openssl/ssl.h>
#include<openssl/err.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
int main(){
    ERR_load_ERR_strings();
    // socketserver::server server("127.0.0.1",443);
    // int x  = BIO_socket(AF_INET,SOCK_STREAM,0,0);
    
    
    struct sockaddr_in in;
    in.sin_family=AF_INET;
    in.sin_addr.s_addr=inet_addr("127.0.0.1");
    in.sin_port= htons(8089);
    int sockets = socket(AF_INET,SOCK_STREAM,0);
    // bind(sockets,(struct sockaddr*)&in,sizeof(in));
    
    SSL_CTX * ctx = SSL_CTX_new(SSLv23_client_method());
    if( SSL_CTX_use_certificate_file(ctx,"cert.crt",SSL_FILETYPE_PEM)<=0)perror("error 1");
SSL_CTX_set_default_passwd_cb_userdata(ctx,(void *)"12345678");
if(SSL_CTX_use_PrivateKey_file(ctx,"key.pem",SSL_FILETYPE_PEM)<=0)perror("ERROR 2");
if(!SSL_CTX_check_private_key(ctx))perror("error");
connect(sockets,(sockaddr*)&in,sizeof(in));
SSL *ssl = SSL_new(ctx);
SSL_set_connect_state(ssl);
SSL_set_fd(ssl,sockets);
// BIO *b = BIO_new_ssl(ctx,1);
// BIO_get_ssl(b,ssl);
// BIO_set_conn_hostname(b,"www.example.com:https");
if(SSL_connect(ssl)<=1)printf("connection error %s",ERR_error_string(ERR_get_error(),0));
char *xb="GET / HTTP/1.1\r\nHost: example.com \r\nConnection:close\r\n\r\n";
int w = SSL_write(ssl,xb,strlen(xb));
printf("\n%d\n",w);



printf("connection error %s",ERR_error_string(ERR_get_error(),0));
    return 0;

}