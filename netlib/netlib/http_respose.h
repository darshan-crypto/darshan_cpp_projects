#include<string>
class http_respose
{
private:
    /* data */
    std::string st;
public:
    http_respose(std::string,std::string);
    std::string getResponse();
      
};

http_respose::http_respose(std::string header,std::string payload)
{
    st.append(header);
    st.append(payload);
}


std::string http_respose::getResponse(){


    return st;
}
