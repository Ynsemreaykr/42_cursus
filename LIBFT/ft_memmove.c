#include "libft.h"

void *ft_memcpy(void *dest,const void *src,size_t n);

void *ft_memmove(void *dest,const void *src,size_t n){

    if(!dest && !src)
        return 0;

    if(dest<src)
        ft_memcpy(dest,src,n);
    
    if(dest>src){

        while(n>0){
            n--;
            ((unsigned char *)dest)[n]=((unsigned char *)src)[n];
        }
    }
    return dest;

}