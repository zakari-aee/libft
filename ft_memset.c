#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
    unsigned char *z;
    size_t i;

    z = (unsigned char *)b;
    i = 0;
    while(i < len)
    {
        z[i] = (unsigned char)c;
        i++;
    }
    return b;
}