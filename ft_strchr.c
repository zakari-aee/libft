#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
    int     i;
    char    t;

    t = (char )c;

    if(!s) return NULL;

    while(s[i])
    {
        if(s[i] == t)
            return ((char *)s);
        i++;
    }
    if(t == '\0')
        return ((char *)s);
    return NULL;



}