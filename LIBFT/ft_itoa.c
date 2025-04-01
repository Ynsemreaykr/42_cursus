#include "libft.h"

static int get_len_num(int n){

    int i=0;

    if(n==0)
        return 1;
    
    while(n>0 || n<0){

        n=n/10;
        i++;
    }
    return i;
}

char *ft_itoa(int n){

    int len;
    char *result;
    long nbr;

    nbr=n;
    len=get_len_num(nbr);

    if(n<0){
        len++; // burdaki arttirmanin amaci stringde sayinin basina eksi koymak icindir
        nbr*=-1;
    }

    result=(char *)malloc((len+1)*sizeof(char));

    if(result==NULL)
        return NULL;

    result[len]='\0';

    while(nbr>0){

        result[--len]=nbr%10+48;
        nbr=nbr/10;
    }

    if(n<0)
        result[0]='-';

    if(n==0)
        result[0]=48;

    return result;
    // printf("%s\n",ft_itoa(0));
}