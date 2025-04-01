#include "libft.h"

void *ft_memset(void *dest,int c,size_t len){

    unsigned char *ptr;

    ptr=dest;

    while(len>0){
        *ptr=c;
        ptr++;
        len--;
    }
    return dest;
}