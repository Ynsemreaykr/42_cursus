#include "libft.h"

char *ft_strchr(const char *str,int c){

    int i=0;
    while(str[i]!='\0' ){

        if(str[i]==(char)c)
            return ((char*)(str+i));
            i++;
    }    
    return 0;

    /*
    char str[20]="yunus emre caliskan";
    printf("%d\n",str);
    printf("%d",ft_strchr(str,'g'));
    */
}