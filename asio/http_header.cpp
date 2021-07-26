#include<iostream>
#include<asio.hpp>
using namespace std;
using namespace asio;
using namespace asio::ip;
char maindata[3000];
void grabdata(tcp::socket& x){
    
x.async_read_some(buffer(maindata,4),[&](error_code ec,size_t readed){
cout << "aysync";
if (!ec)
{
    for(int i =0;i<readed;i++){
        cout << maindata[i];
    }
   grabdata(x);
}



}


 );

}
int main(int argc, char const *argv[])
{
    io_context i;
    tcp::resolver resv(i);
    tcp::resolver::results_type r = resv.resolve("example.com","80");
     
    tcp::socket s(i);
    connect(s,r);
    if (s.is_open())
    {
        cout << "\n connection created\n";

        char header[] =
         "GET / HTTP/1.1 \r\n"
        "Host: example.com \r\n"
         "Connection : keep-alive \r\n"
        "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:86.0) Gecko/20100101 Firefox/86.0\r\n"
       
        "Accept : text/html \r\n\r\n";

         
        // 	char header[] =
		// "GET / HTTP/1.1 \r\n"
		// "Host: example.com \r\n"
		// "Connection: keep-alive \r\n"
		// "Accept: text/html\r\n\r\n"
		// ;
s.wait(s.wait_write);
        s.write_some(buffer(header,sizeof(header)));

//   cout << header;
s.wait(s.wait_read);
   int x = s.available();
   cout << x;
   char v[x];
   
  grabdata(s); 
//s.async_read_some(buffer(v,1),[&](error_code ec,size_t readed){
//cout<< ec.message();
//cout << endl<<readed;
//});
 //  s.read_some(buffer(v,x));
int i = 20;
while (i<x)
{
    //cout << v[i];
i++;
}
//cout << header;

    }




    return 0;
}
