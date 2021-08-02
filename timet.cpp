#include<iostream>
#include<unistd.h>
#include<thread>
#include"netlib/http_header.h"
int main(int argc, char const *argv[])
{
  http_header::response_header::response_builder re(HTTP_VERSION::HTTP1,HTTP_STATUS_CODE::Found);
  re.setdate();
  re.setserver("dws");
  re.setcontentencoding(gzip);

  std::cout << re.getrespone();
  //re.sethttpversion(HTTP2);
  //re.sethttpstatuscode(Not_Found);
  //std::cout << re.getrespone();
  //  re.sethttpversion(HTTP1);
  //  re.sethttpstatuscode(Not_Modified);
   //std::cout << re.getrespone();
  re.sethttpstatuscode(Internal_Server_Error);
  re.setcontetnttype(text_javascript);
  std::cout << re.getrespone();
  return 0;
}
