#include "libft.h"

int ft_strlen(const char *str);

char *ft_strjoin(char const *s1,char const *s2){

    char *result;
    size_t len=ft_strlen(s1)+ft_strlen(s2);
    result=malloc((len+1)*sizeof(char));

    if(result==NULL)
        return NULL;
    
    size_t i=0;

    while(s1[i]!='\0'){
        
        result[i]=s1[i];
        i++;
    } 
    i=0;

    while(s2[i]!='\0'){
        
        result[ft_strlen(s1)+i]=s2[i];
        i++;
    }

    result[len]='\0';
    return result;

    //     char s1[20]="yun";
    // char s2[20]=" bn";

    // char *d=ft_strjoin(s1,s2);
    // printf("%s\n",d);

}