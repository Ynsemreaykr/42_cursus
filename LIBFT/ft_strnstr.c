#include "libft.h"

char *ft_strnstr(const char *src,const char *find,size_t len){

    size_t i=0;
    size_t j=0;

    if(find[j]=='\0')
        return ((char *)src); // return *str olsaydı ilk karakteri döndürürdü
// ama şu anda src stringini geri döndürdük

    while(src[i]!='\0' && i<len){

        while(src[i+j]==find[j] && i+j<len){
            if(find[j+1]=='\0') // burdaki if, find ın tamamı varmı yokmu diye kontrol eder
                return (char *)&src[i];
            j++;
        }
        j=0;
        i++;
    }
    return 0;
    /*
        char str[20]="hello world yunus";
    char str2[20]="world";

    printf("%s",ft_strnstr(str,str2,20));
    */
}