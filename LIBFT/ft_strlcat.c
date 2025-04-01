#include "libft.h"

int ft_strlen(const char *str);
size_t ft_strlcpy(char *dest,const char *src,size_t dest_size);


size_t ft_strlcat(char *dest,const char *src,size_t dest_size){

    size_t src_len=ft_strlen(src);
    size_t dest_len=ft_strlen(dest);

    if(dest_size<=dest_len)
        return dest_size+src_len;
        
    ft_strlcpy(dest+dest_len,src,dest_size-dest_len);
    // burada 3. parametre olarak src_len kullanmamamızıın sebebi, dest dizisinde
    // src_len kadar boşluk kalmamış olabilir ve bu bellek taşmasına sebep olur
}