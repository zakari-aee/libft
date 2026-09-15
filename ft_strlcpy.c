#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t src_len;

    src_len = ft_strlen(src);
    
    if(dstsize == 0)
        return (src_len);
    
    i = 0;
    while(i < dstsize - 1 && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (src_len);
    
}