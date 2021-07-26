#include<string.h>
#include<asio.hpp>
typedef const asio::error_code& error;
typedef void (*handler)   (error);
typedef void (*writehandler)(error,size_t);
typedef writehandler readhandler;
namespace tcp{

class server{

private:

int port;
std::string ip_address;
asio::io_context io_context;
asio::ip::tcp::acceptor *acceptor;
asio::error_code ec;


public:

asio::ip::tcp::socket *socket;

server(std::string,int);
size_t write_some(std::string);
size_t  read_some( std::string*,int);
size_t avalible();
void close();
bool isopen();
void waitforread();
void waitforwrite();
void waitforerror();
void accept();
void shutdownrecive();
void shutdownsend();
void shutdown();

void async_wait_for_write(handler);
void async_wait_for_read(handler);
void async_wait_for_error(handler);
void async_write_some(std::string,writehandler);
void async_read_some(std::string*,int length,readhandler);
~server();
};


server::server(std::string ip,int port){
    ip_address = ip ;
    this->port = port;
    asio::ip::address a4;
    
    a4.from_string(ip);
    acceptor = new  asio::ip::tcp::acceptor(io_context,asio::ip::tcp::endpoint(a4,port));
   
    socket = new asio::ip::tcp::socket(io_context);


};
server::~server(){
    close();
}
void server::async_wait_for_write(handler x){
    socket->async_wait(socket->wait_write,x);
  io_context.run();


}
void server::async_wait_for_read(handler x){
    socket->async_wait(socket->wait_read,x);
  io_context.run();
}
void server::async_wait_for_error(handler x){
    socket->async_wait(socket->wait_error,x);
  io_context.run();
}
void server::async_write_some(std::string text,writehandler w){
    socket->async_write_some(asio::buffer(text),w);
    io_context.run();
}
void server::async_read_some(std::string *text,int length,readhandler w){
  //  char* m;

    socket->async_read_some(asio::buffer(text,length),w);
    io_context.run();
    

}
void server::shutdownrecive(){socket->shutdown(socket->shutdown_receive);}
void server::shutdownsend(){socket->shutdown(socket->shutdown_send);}
void server::shutdown(){socket->shutdown(socket->shutdown_both);}
void server::waitforread(){socket->wait(socket->wait_read);};
void server::waitforwrite(){socket->wait(socket->wait_write);};
void server::waitforerror(){socket->wait(socket->wait_error);};





void server::accept(){
(*acceptor).accept(*socket);
};
size_t server::avalible(){
    return socket->available();
}
bool server::isopen(){
    return socket->is_open();
}
void server::close(){
    socket->cancel();
    
    socket->close();
    
}
size_t server::write_some(std::string text){
    return socket->write_some(asio::buffer(text));
    
}
size_t server::read_some(std::string *a,int length){
    char c[length];

int readed =  socket->read_some(asio::buffer(c,length));
std::string s(c);
*a = s;

return readed;
}


// server::~server(){
//  //    if(isopen())close();
//      delete &ip_address;
// //     delete &port;
//      delete &io_context;
//      delete &socket;
//      delete &acceptor;
//      delete &ec;
// }
class client {

public :

client(std::string ,int );
asio::io_context iocontext;
std::string ip_address;
int port ;
void connect();
size_t write_some(std::string);
size_t  read_some(std::string *,int);
size_t avalible();
void close();
bool isopen();
void waitforread();
void waitforwrite();
void shutdownrecive();
void shutdownsend();
void shutdown();

void waitforerror();
void async_wait_for_read(void *x (const asio::error_code ec) ){
    socket->async_wait(socket->wait_read,x);
};
private:
asio::ip::tcp::resolver *resolver;
asio::ip::tcp::resolver::results_type endpoints;
asio::ip::tcp::socket *socket;
};
client::client(std::string server_ip,int port){
ip_address = server_ip;
this->port = port;
resolver  =  new asio::ip::tcp::resolver(iocontext);
endpoints = resolver->resolve(server_ip,std::to_string(port));
socket = new asio::ip::tcp::socket(iocontext);
};
void client::connect(){
     asio::ip::address a4;
    
    a4.from_string(ip_address);
socket->connect(asio::ip::tcp::endpoint(a4,port)); 

};
void client::shutdownrecive(){socket->shutdown(socket->shutdown_receive);}
void client::shutdownsend(){socket->shutdown(socket->shutdown_send);}
void client::shutdown(){socket->shutdown(socket->shutdown_both);}
size_t client::avalible(){
    return socket->available();
}
bool client::isopen(){
    return socket->is_open();
}
void client::waitforread(){socket->wait(socket->wait_read);};
void client::waitforwrite(){socket->wait(socket->wait_write);};
void client::waitforerror(){socket->wait(socket->wait_error);};
void client::close(){
    socket->cancel();
    
    socket->close();
    
}
size_t client::write_some(std::string text){
    return socket->write_some(asio::buffer(text,text.size()));
    
}
size_t client::read_some(std::string *b,int length){
  
    char c[length];

int readed =  socket->read_some(asio::buffer(c,length));
std::string s(c);
*b = s;

return readed;
};

}