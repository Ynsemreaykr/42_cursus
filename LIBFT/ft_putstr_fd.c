#include "libft.h"
#include <unistd.h>

void ft_putstr_fd(char *s,int fd){

    int i=0;
    while(s[i]!='\0'){
        write(fd,&s[i],1);
        i++;
    }

    //     int main(){ 
        
    //     char *s="hello";
    //     ft_putstr_fd("hello",1);

    // }  
}