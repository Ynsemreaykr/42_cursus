#include "libft.h"

void *ft_memchr(const void *s,int c,size_t n){

    const unsigned char *ptr=(const unsigned char*)s;
    // void* herahngi bir veri türünü temsil edebilir ve doğru kkullanımı için
    // void* ın char* tipine dönüşütürülmesi gereklidir

    size_t i=0;
    while(i<n){
        if((unsigned char)c==ptr[i])
            return &s[i];
        i++;
    }
    return NULL;

   /*
    char str[20]="hello world!";

    printf("%d\n",str);
    printf("%d",ft_memchr(str,'\0',13));
    */
}