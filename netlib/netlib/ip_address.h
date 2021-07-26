#include<asio.hpp>
namespace ip_address
{
class ip_service{

public:
ip_service(std::string,int);
ip_service();

int getport();
std::string getip();
void setip(std::string);
void setport(int);
asio::ip::tcp::endpoint   tcp_endpoint();

private:
int port;
std::string ip;

};
ip_service::ip_service(std::string ip,int port){
this->ip = ip;
this->port = port;

};
int ip_service::getport(){return port;};
std::string ip_service::getip(){return ip;};

    class address_details
    {
    private:
        asio::ip::address *a;
    public:
     address_details(asio::ip::address);
     address_details(asio::ip::address_v4);
     address_details(asio::ip::address_v6); 
     bool is_loopback(){
         return a->is_loopback();
     }
	


bool is_multicast(){return a->is_multicast();}
	


bool is_unspecified(){return a->is_unspecified();}
	

bool is_v4(){return a->is_v4();}
	


bool is_v6(){return a->is_v6();}
	

asio::ip::address_v4 to_v4(){
    return a->to_v4();
}
	
asio::ip::address_v6 to_v6(){
    return a->to_v6();
}
const char* to_string(){
   const char * x ;
    if (is_v4())
    {

        x =  to_v4().to_string().data();
    }
    else  x =  to_v6().to_string().data();
return x;
    
}


	

    };
    
 
    address_details::address_details(asio::ip::address address)
    {
   *a = address;
    }
     address_details::address_details(asio::ip::address_v4 address) 
    {
           *a = address;
           
    }
     address_details::address_details(asio::ip::address_v6 address)
    {
           *a = address;
    };
  class ipv4_details
  {
  private:
    asio::ip::address_v4 *v4;
  public:
       ipv4_details( asio::ip::address_v4 *);
       ipv4_details( asio::ip::address_v4);
      bool is_loopback();
       bool is_multicast();
       bool is_unspecified();
         asio::ip::address_v4::bytes_type to_bytes();
         asio::ip::address_v4::uint_type to_uint();
         unsigned long to_ulong();
      ~ipv4_details();
  };
   asio::ip::address_v4::bytes_type ipv4_details::to_bytes(){return v4->to_bytes();};
   asio::ip::address_v4::uint_type ipv4_details::to_uint(){return v4->to_uint();};
   unsigned long  ipv4_details::to_ulong(){return v4->to_ulong();};
  ipv4_details::ipv4_details( asio::ip::address_v4 *v4)
  {
      this->v4=v4;
  }
   ipv4_details::ipv4_details( asio::ip::address_v4 v4)
  {
      *(this->v4)=v4;
  }
  bool ipv4_details::is_loopback(){
         return v4->is_loopback();
     }
	


bool ipv4_details::is_multicast(){return v4->is_multicast();}
	


bool ipv4_details::is_unspecified(){return v4->is_unspecified();}
	  
  ipv4_details::~ipv4_details()
  {
  }
    
} 
