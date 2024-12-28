#include "libft.h"

int ft_strlen(const char *str);

char *ft_strmapi(char const *s,char (*f)(unsigned int,char)){

    char *str;
    size_t i=0;

    str=malloc((ft_strlen(s)+1)*sizeof(char));

    if(s==NULL)
        return NULL;

    if(str==NULL)
        return NULL;

    while(s[i]!='\0'){


        str[i]=f(i,s[i]);
        i++;
    }   

    str[i]='\0';
    return str;

// char f(unsigned int x,char a){
//     return a+1;
// }

// int main(){ 

//     char *str="hello";
//     char *result;
//     result=ft_strmapi(str,f);
//     printf("%s\n",result);
//     bu fonksiyon, bir stringin her karakteri üzerinde kendi foknumuzu olusturarak ozgurce karakterleri degistirebilmemizi saglar
// }  


}