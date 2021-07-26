#include<iostream>
#include<mysql/mysql.h>
using namespace std;
int main(int argc, char const *argv[])
{
       MYSQL m;
       MYSQL *m1 = mysql_init(&m);
      if(! mysql_real_connect(m1,0,"root","darshan0","x2",0,0,0)){
          fprintf(stderr, "Failed to connect to database: Error: %s\n",
          mysql_error(&m));
       }
       else{
           mysql_query(m1,"select * from mytable");
           MYSQL_RES *res = mysql_store_result(m1);
         while(  MYSQL_ROW row  =  mysql_fetch_row(res)){
        unsigned long *x = mysql_fetch_lengths(res);
       // for(int i=0;i<mysql_num_fields(res);i++)  {
        //    cout << endl << *(row+i);
           // cout << *mysql_fetch_lengths(res);
          // cout << x[i];
       /// }
       MYSQL_FIELD *attr = mysql_fetch_fields(res);
       for(int  i=0;i<mysql_num_fields(res);i++)
        {
        cout << endl << (attr+i)->name;
        }
       } 
        }
        
       return 0;
}
