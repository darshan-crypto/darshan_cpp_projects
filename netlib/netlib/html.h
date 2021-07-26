#include<stdio.h>
#include<string.h>
// #include<openssl/bio.h>
// #include"socketserver.h"
// #include"settings.h"

void  send_html(ssl *s,char *name){
printf("\n sending html");
std::string st=STATIC_DIR;
st.append("/");
st.append(name);
FILE *x = fopen(st.c_str(),"r");
char read[2048]={0};
size_t readded;
BIO * temp = BIO_new_fp(x,1);
if(temp==0){
    printf("error %s",st.c_str());
}
while(BIO_read_ex(temp,read,2048,&readded)!=0){



// printf("\n%s %d",read,readded);
// if(b !=0){
//    BIO_write(b,read,readded);
// }
// else{
int x = s->write_some(read,readded);
// int x =write(s->peersocket,read,readded);
// send(s->peersocket,read,readded,0);
//perror("hi");
//printf("\n %d bytes written ",x);
// }
}


}

