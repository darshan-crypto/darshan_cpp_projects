#include<iostream>
#include"tcp.h"
#include<signal.h>
void pnt(int x){
    std::cout << "\n stopping";
    
    exit(0);
};
void x(const  asio::error_code &ec){
    std::cout<< "ss";

};
int main(int argc, char const *argv[])
{
    signal(SIGSTOP,pnt);
    signal(SIGINT,pnt);
    tcp::server server("192.168.43.204",4444);
    // while (1)
    // {
        /* code */
    server.accept();
   server.waitforwrite(); 
 //   server.async_wait_for_read(x);
    server.write_some("hello");
    server.close();
 //   }
    
    return 0;
    
}
