
#define ASIO_STANDALONE
#define HTTP 80
#define FTP 21
#define HTTPS 443
#define DAYTIME 13
#include<asio/io_context.hpp>
#include<asio/connect.hpp>
#include<asio/ip/tcp.hpp>
#include<asio/ip/host_name.hpp>
namespace netlib{

std::string host_name(asio::error_code&ec){return asio::ip::host_name(ec);}
std::string host_name(){return asio::ip::host_name();}
}

class base_socket:protected asio::ip::tcp::socket{



    
};
