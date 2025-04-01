#include "libft.h"

int ft_strlen(const char *str);

char *ft_substr(char const *s,unsigned int start,size_t len){

    char *result;
    unsigned int i=0;
    

    if(s==NULL || start>=ft_strlen(s)){

        result=malloc(1*sizeof(char));
        result[0]='\0';
        return result;
    }

    result=malloc((len+1)*sizeof(char));

    if(result== NULL)
        return NULL;

    while(i<len){

        result[i]=s[start];
        i++;
        start++;
    }
    result[i]='\0';
    return result;

    //     char s[20]="yunus emre caliskan";

    // char *d;
    // d=ft_substr(s,6,4);
    // printf("%s\n",d);
}