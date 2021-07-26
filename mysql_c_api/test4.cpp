#include<iostream>
#include<string.h>
#include<cstring>
#include<mysql/mysql.h>
using namespace std;
int main(int argc, char const *argv[])
{
        MYSQL m;
       MYSQL *m1 = mysql_init(&m);
      if(! mysql_real_connect(&m,0,"root","darshan0","x2",0,0,0)){
          fprintf(stderr, "Failed to connect to database: Error: %s\n",
          mysql_error(&m));

       }
       else
       {
        cout << endl << "no error ";
     const   char *real_text[2] = {"param1","param2"};
        char *bind_text[2] = {"name1","name2"};
        unsigned long int length[2] = {5,5};
        MYSQL_BIND b[2];
        b[0].is_null = 0;
        b[0].length = &length[0];
        b[0].buffer = bind_text[0];
        b[0].buffer_type = MYSQL_TYPE_STRING;
        b[1].is_null = 0;
        b[1].length = &length[1];
        b[1].buffer = bind_text[1];
        b[1].buffer_type = MYSQL_TYPE_STRING;

mysql_bind_param(&m,2,b,real_text);

//char * q  = "create table tab1( param1 varchar(20), param2 varchar(20) )";
//mysql_query(&m,q);
  char query[1000],*end;

end = strmov(query,"INSERT INTO test_table values(");
end = strmov(end,"X'");
end += mysql_hex_string(end,"What is this",12);
end = strmov(end,"',X'");
end += mysql_hex_string(end,"binary data: \0\r\n",16);
end = strmov(end,"')");
  
  
       }
       
    
    return 0;
}
