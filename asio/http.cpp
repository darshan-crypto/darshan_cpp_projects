#include<iostream>
#include<asio.hpp>
using namespace std;
using namespace asio;
using namespace asio::ip;
#include<vector>
int main(int argc, char const *argv[])
{
    std::vector<std::string> values;
    std::cout << "IP addresses: \n";
io_service io_service;
tcp::resolver resolver(io_service);
tcp::resolver::query query(argv[1], "");
for(tcp::resolver::iterator i = resolver.resolve(query);
                            i != tcp::resolver::iterator();i++)
{
    tcp::endpoint end = *i;
    std::cout << end.address() << ' ';
}
std::cout << '\n';


    return 0;
}
