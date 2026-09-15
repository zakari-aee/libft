#include "libft.h"

/*
** ft_memcmp: compares n bytes of s1 and s2.
** Returns 0 if equal, else the difference of first differing bytes.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t      i;
    const unsigned char *c1;
    const unsigned char *c2;

    c1 = (const unsigned char *)s1;
    c2 = (const unsigned char *)s2;

    i = 0;
    while(i < n)
    {
        if(!(c1[i] == c2[i]))
            return (c1[i] - c2[i]);
        i++;
    }
    return 0;

}