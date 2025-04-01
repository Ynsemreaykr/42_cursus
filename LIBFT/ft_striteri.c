#include "libft.h"

void ft_striteri(char *s,void (*f)(unsigned int,char *)){

    unsigned int i=0;

    if(s!=NULL && f!=NULL)
        while(s[i]!='\0'){
            f(i,&s[i]);
            i++;
        }


    // void f(unsigned int i,char *a){
    //     *a=*a+i;
    // }

    // int main(){ 

    //     char s[20]="hello world";
    // // bu fonksiyon strmapi gibi kendisine bagimsiz fonk pointeri gonderilerek string karakteri uzerinde islem yapmayi saglar
    //     ft_striteri(s,f);
    //     printf("%s\n",s);
    // }  
}