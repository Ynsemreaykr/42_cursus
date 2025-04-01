#include "libft.h"

void *ft_memcpy(void *dest,const void *src,size_t n){
// dest: kopyalanacak adres
// src: kopyalanan veri adresi
// n: kaç veri kopyalanacak
// size_t n: hangi türde veri olduğu önemli değil, n buarada veri tipi değil bayt tutar
    size_t i=0;

    if(!src || !dest)
        return 0;

    while(i<n){
        
        ((unsigned char*)dest)[i]=((unsigned char*)src)[i];
        i++;
    }
    return dest;
}