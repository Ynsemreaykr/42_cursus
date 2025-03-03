#include "libft.h"

int ft_strlen(const char *str);


size_t ft_strlcpy(char *dest,const char *src,size_t dest_size){

    // kopyalanacak adres, kopyalanan, kopyalanacak adresin bellek boyutu

    int src_len=ft_strlen(src);

    size_t i=0;
    if(i<dest_size){

        while(src[i] && i<dest_size-1){
            dest[i]=src[i];
            i++;
        }
        dest[i]='\0';
    }
    return src_len;
}