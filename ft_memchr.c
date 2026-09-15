#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
    size_t      i;
    const unsigned char *p;
    unsigned char t;

    p = (const unsigned char *)s;
    t = (unsigned char)c;
    
    i = 0;
    while(i < n)
    {
        if(p[i] == t)
            return ((void *)&p[i]);
        i++;
    }
    return NULL;
}