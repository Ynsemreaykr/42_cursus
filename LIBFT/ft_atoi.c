#include "libft.h"

int ft_atoi(const char *str){

    int i=0;
    int sign=1;
    int res=0;

    while(str[i]==32 || (str[i]>=9 && str[i]<=13))
        i++;

    if(str[i]=='+' || str[i]=='-'){
        if(str[i]=='-')
            sign*=-1;
        i++;
    }

    while(str[i]>='0' && str[i]<='9'){
        res=(res*10)+(str[i]-48);
        i++;
    }
    return sign*res;

    /*
        char str[20]="123";
        printf("%s\n",str);
        printf("%d\n",str);
        printf("%d\n",ft_atoi(str));
    */
    }