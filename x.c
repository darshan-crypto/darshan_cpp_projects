#include<stdio.h>
#include<openssl/bio.h>

int main(){
BIO *b= BIO_new_file("swap.c","r");
char raex[1000]={0};

while (BIO_read(b,raex,1000)!=0)
{
    printf("%s",raex);    
}


    return 0;
}