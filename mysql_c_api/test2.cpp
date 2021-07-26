#include<iostream>
#include<mysql/mysql.h>
using namespace std;
int main(int argc, char const *argv[])
{
      MYSQL m;

       MYSQL *m1 = mysql_init(&m);
       if(! mysql_real_connect(m1,0,"root","darshan0","x2",0,0,0))
       {
       fprintf(stderr, "Failed to connect to database: Error: %s\n",
       mysql_error(m1));
       }   
       else{
           cout << "connection created";
           mysql_query(m1,"select * from mytable");
           MYSQL_RES *res = mysql_store_result(m1);
           uint64_t rows = mysql_num_rows(res);
           unsigned int  columns = mysql_num_fields(res);
           cout << "\n rows "<<rows<<" columns "<<columns;
//           int i=0;
        //    while(MYSQL_ROW x=mysql_fetch_row(res)){
        //         //MYSQL_FIELD *b = mysql_fetch_field(res);
        //        for(int i=0;i<mysql_num_fields(res);i++){
        //         cout <<endl<< x[i] ;
        //   
          //   }
          MYSQL_FIELD *m6 ;
       while( (m6 = mysql_fetch_field(res))){
           cout << m6->name;
           
       }

    MYSQL_FIELD *field;

// while((field = mysql_fetch_field(res)))
// {
//     printf("field name %s\n", field->name);
// }
    //       }
       // MYSQL_ROW row;
//unsigned int num_fields;
//unsigned int i;

// num_fields = mysql_num_fields(res);
// while ((row = mysql_fetch_row(res)))
// {
//    unsigned long *lengths;
//    lengths = mysql_fetch_lengths(res);
//    for(i = 0; i < num_fields; i++)
//    {
//        printf("%s"
//               ,row[i] ? row[i] : "NULL");
//    }
//    printf("\n");
// }

       }
      return 0;
}
