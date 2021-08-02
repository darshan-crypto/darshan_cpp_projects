#include<asio.hpp>
#include<iostream>
using namespace std;
using namespace asio::ip;
#include<asio/ssl.hpp>
 bool verify_certificate(bool preverified,
      asio::ssl::verify_context& ctx)
  {
    // The verify callback can be used to check whether the certificate that is
    // being presented is valid for the peer. For example, RFC 2818 describes
    // the steps involved in doing this for HTTPS. Consult the OpenSSL
    // documentation for more details. Note that the callback is called once
    // for each certificate in the certificate chain, starting from the root
    // certificate authority.

    // In this example we will simply print the certificate's subject name.
    char subject_name[256];
    
    X509* cert = X509_STORE_CTX_get_current_cert(ctx.native_handle());
    
    X509_NAME_oneline(X509_get_subject_name(cert), subject_name, 256);
    std::cout << "Verifying " << subject_name << "\n";

    return preverified;
  }
typedef asio::ssl::stream<asio::ip::tcp::socket> ssl_socket;
int main(int argc, char const *argv[])
{
    asio::io_context io;
    asio::ssl::context ctx(asio::ssl::context::sslv23);
    ctx.load_verify_file("/home/darshan/cert.pem");
tcp::resolver resolver(io);
    
     ssl_socket s(io,ctx);
tcp::resolver::query query("www.boost.org","https");
  s.set_verify_mode(asio::ssl::verify_peer);
   s.set_verify_callback(&verify_certificate);
 connect(s.lowest_layer(),resolver.resolve(query));
  if(s.lowest_layer().is_open()){cout << "open";
  s.handshake(asio::ssl::stream_base::client);
 s.lowest_layer().wait(s.lowest_layer().wait_write);
  s.write_some(asio::buffer("GET / HTTP/1.1 \r\nHost:www.boost.org\r\nConnection:close\r\n\r\n"));
  s.lowest_layer().wait(s.lowest_layer().wait_read);
  cout << s.lowest_layer().available();
 char m[10000];
 int x = s.read_some(asio::buffer(m,9998));
for(int i=0;i<x;i++)cout << m[i];
  }
    return 0;
}
