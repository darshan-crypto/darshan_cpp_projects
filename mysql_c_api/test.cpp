#include<iostream>
#include<mysql/mysql.h>
using namespace std;
int main(int argc, char const *argv[])
{
  if( mysql_library_init(0,0,0))
  {

      cout << "error";
  }
   MYSQL m;

  MYSQL *m1 = mysql_init(&m);
 if (m1==NULL)
 {
    cout << "null";
 }
 
  if(! mysql_real_connect(&m,0,"root","darshan0",0,0,0,0)){
       fprintf(stderr, "Failed to connect to database: Error: %s\n",
          mysql_error(&m));
  }   
  else{
 char n[10];
if(mysql_get_option(&m,mysql_option::MYSQL_DEFAULT_AUTH,n)){
      fprintf(stderr, "mysql_get_option() failed  : %s\n " ,     mysql_error(&m));
}
cout << "else "<<n;
//if(!mysql_get_ssl_cipher(&m))cout << "not enrypted ";


  }
//if(mysql_refresh(&m,REFRESH_HOSTS))printf("error on rerese");
 if(  mysql_query(&m,"SHOW DATABASES"))cout <<"databse error";
 //uint64_t C0 =  mysql_affected_rows(&m);
 
   uint16_t C0 = mysql_field_count(&m);
   cout << C0;
    return 0;
}
