#include "libft.h"

// bir stringi gonderilen c karakterlerine parcalar ve iki boyutlu * diziye atar

int ft_strlen(const char *str);
char *ft_substr(char const *s,unsigned int start,size_t len);


static int ft_max_len(char const *s,char c){

    int res=0;
    int i=0;
    int toplam_kelime=0;


    while(s[i]!='\0'){
     
        if(s[i]!=c)
            res++;

        else if(s[i]==c && s[i-1]!='\0' && s[i-1]!=c)
            toplam_kelime++;

    i++;
    }
    

    if(s[i-1]!=c)
        toplam_kelime+=1;

    return toplam_kelime;
}

static void ft_kelime_parcala(char const *s,char c,char **result){


    int i=0;
    int start=0;

    while(s[i]!='\0'){

        if(s[i]==c && s[i-1]!=c){

            if(i-start!=0){

                *result=ft_substr(s,start,i-start);
                result++;
            }
            start=i+1;
        }
        i++;
    }

    if(s[i-1]!=c)
        *result=ft_substr(s,start,i-start);
    
    if(s[i]!=c)
        result++;

    *result=NULL;       
}

char **ft_split(char const *s,char c){

    char **result;
    
    if(s==NULL)
        return NULL;

    if(s[0]=='\0' || ft_max_len(s,c)==0){

        result=(char **)malloc(sizeof(char *)+1);
        result[0]=NULL;
        return result;
    }

    result=(char **)malloc((ft_max_len(s,c)+1)*sizeof(char *));// once kac kelime oldugu bulunup ona gore heap te yer acilir
// result a char** tipinde keliem sayısının bir fazlası kadar(o fazlalık '\0') yer açılır

    if(result==NULL)
        return NULL;

    ft_kelime_parcala(s,c,result);// heapte acilan yere sting parcalanarak atanir
    return result;


    // char s[30]="yunus emre ayiker ";
    
    // char **result;
    // result=ft_split(s,'e');

    // for(int i=0;i<4;i++)
    //     printf("%s\n",result[i]);
}