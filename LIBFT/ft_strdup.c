#include "libft.h"

int ft_strlen(const char *str);

char *ft_strdup(const char *src){


    char *result;
    int len;
    int i;

    len=ft_strlen((const char *)src);

    result=malloc((len+1)*sizeof(char));
    // malloc a len+1 gönderilmesinin sebebi kopyalama işleminden sonra \0 konulması içindir

    if(result == NULL)
        return NULL;

    for(i=0;i<len;i++)
        result[i]=src[i];
    result[len]='\0';

    return result;

    //     char src[20]="hello world yunus";
    // char *ptr=ft_strdup(src);
    // printf("src bellek adresi: %d\n",&src); // stack teki bellek adresi
    // printf("%s\n",src);
    // printf("%s\n",ptr);
    // printf("kopya bellek adresi: %d\n",&ptr); // heap teki bellek adresi

    // free(ptr);
}