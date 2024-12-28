#include "libft.h"

char *ft_strchr(const char *str,int c);
char *ft_substr(char const *s,unsigned int start,size_t len);

char *ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
    
	if (s1==NULL || set==NULL)
		return (0);

    // set içersinde s1 in ilk harflerinden ortak karakter bulduklarını atlar
	while (*s1 && ft_strchr(set, *s1))
		s1++;

	i = ft_strlen(s1);

    // set içersinde s1 in son harflerinden ortak olanları atlar
	while (i>0 && ft_strchr(set, s1[i-1]))
		i--;
	
    // en son kırpılan s1 in 0. indexinden kalan uzunluğu kadarı başka diziye atanır
    return (ft_substr(s1, 0, i));


    //    char s[20]="yunus emre";
    // char a[3]="re";
    // printf("%s\n",ft_strtrim(s,a));
}