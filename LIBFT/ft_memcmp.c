#include "libft.h"

int ft_memcmp(const void *s1,const void *s2,size_t n){

    const unsigned char *p1=(const unsigned char *)s1;
    const unsigned char *p2=(const unsigned char *)s2;
    
    size_t i=0;
    while(i<n){

        if(p1[i]>p2[i])
            return p1[i]-p2[i];
 
        if(p1[i]<p2[i])
            return p1[i]-p2[i];
        i++;
    }
    return 0;

    /*
     char str[20]="hello\0emre";
    char str2[20]="hello\0yunus";

    printf("%d\n",ft_memcmp(str,str2,8));
    printf("%d",memcmp(str,str2,8));
    */
}