#include "libft.h"

void ft_putchar_fd(char c,int fd);

void ft_putnbr_fd(int n,int fd){

    long nb;
    nb=n;

    if(nb<0){
        ft_putchar_fd('-',fd);
        nb*=-1;
    }

    if(nb<=9)
        ft_putchar_fd(nb+48,fd);

    if(nb>=10){
        ft_putnbr_fd(nb/10,fd);
        ft_putnbr_fd(nb%10,fd);
    }

    //     int i=-123;
    // ft_putnbr_fd(i,1);
}