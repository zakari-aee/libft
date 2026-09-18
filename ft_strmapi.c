#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *res;

    if(!s || !f)
        retrun NULL;
    
    res = (char *)(malloc(sizeof(char) * ft_strlen(s) + 1));
    
    if (!res) return NULL;
    unsigned int    i;
    i = 0;
    while(s[i])
    {
        res[i] = f(i,s[i]);
        i++;
    }
    res[i] = '\0';
    return res;
}