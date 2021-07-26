#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
namespace socketserver
{
    class server
    {

    public:
        server(char *, int, int);
        void acceptconnection();
        size_t read_some(char *, int);
        size_t write_some(char *, int);
       void  closeconnection();
       void checksome();
       void closepeer();
       void bindconnection();
        int mysocket, peersocket;
        int  getserversocket(){
            return mysocket;
        };
    //    struct  getpeer()
        struct sockaddr_in main, peer;
    private:
        int b,l;
        int opt;
        socklen_t len = sizeof(peer);
    };

    server::server(char *host, int port, int nclients)
    {
        main.sin_family = AF_INET;
        main.sin_port = htons(port);
        main.sin_addr.s_addr = inet_addr(host);

        mysocket = socket(AF_INET, SOCK_STREAM, 0);
        setsockopt(mysocket,SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT,&opt,sizeof(opt));
    };
    void server::bindconnection(){
       b= bind(mysocket, (struct sockaddr *)&main, sizeof(main));

    };
    void server::acceptconnection()
    {
       l= listen(mysocket, 10);
        peersocket = accept(mysocket, (struct sockaddr *)&peer, &len);
    }
    size_t server::write_some(char *data, int length)
    {
        
        return send(peersocket, data, len,0);
    }
    size_t server::read_some(char *BUFFER, int len)
    {
        return recv(peersocket,BUFFER,len,0);
      
    }
    void server::closeconnection(){
        close(mysocket);
 
   }
   void server::closepeer(){
         close(peersocket);
   }
   void server::checksome(){
      // printf(" \n socket number %d",mysocket);
      if(b !=0 ){
          printf("bind error");
         perror("x ");
      }
        if(l !=0 ){
          printf("listen error");

      }
   }
}