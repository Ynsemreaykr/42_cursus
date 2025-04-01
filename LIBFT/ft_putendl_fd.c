#include "libft.h"
#include <unistd.h>

void ft_putchar_fd(char c,int fd);
void ft_putstr_fd(char *s,int fd);

void ft_putendl_fd(char *s,int fd){

    if(s!=NULL){
        ft_putstr_fd(s,fd);
        ft_putchar_fd('\n',fd);
    }

    // ft_putendl_fd("hello",1);

}