#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;
    unsigned char *dstt;
    const unsigned char *srcc;

    dstt = (unsigned char * )dst;
    srcc = (const unsigned char *)src;

    i = 0;

    if(!dst && !src)
        return NULL;

    while(i < n)
    {
        dstt[i] = srcc[i];
        i++;
    }
    return dst;

}

int main()
{
    char s[] = "zakariae";
    char d[5] ;

    size_t n = 4;

    ft_memcpy(d,s,n);
    printf("%s",d);

}