#include "libft.h"

void *ft_calloc(size_t count,size_t size){

    char *ptr;
    size_t i=0;
    size_t  x;

    ptr=(char *)malloc(count*size);

    if(ptr==NULL) // if(!ptr)
        return NULL;

    x=count*size;
// 4 tane int lık alan açılamk istenirse 4*4=16 degeri x e atanır 
    
    for(i=0;i<x;i++)
        ptr[i]=0;

    return ptr;

    
    // int *ptr=(int*)ft_calloc(4,sizeof(int));
    
    // for(int i=0;i<4;i++)
    //     printf("%d\n",ptr[i]);
    //     free(ptr);
}