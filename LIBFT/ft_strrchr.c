#include "libft.h"

int ft_strlen(const char *str);

char *ft_strrchr(const char *str,int c){

    int i=ft_strlen(str)-1;

    if (c == '\0')
		return ((char *)&str[i]); 
    // bulduğumuz adresi char* türünde return ettik
    
    while(i>=0){
        if(str[i]==(unsigned char)c)
            return ((char *)str)+i;
        i--;
    }
    return NULL;


    /*
    char str[20]="hello world!";
    printf("%d\n",str);
    printf("%d",ft_strrchr(str,'\0'));
    yani dizinin sonlandığı karakterin adresini bulduk
    */
}