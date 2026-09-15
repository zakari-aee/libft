#include "libft.h"

char	*ft_strdup(const char *s1)
{
    size_t     i;
    size_t     len;

    char *ptr;

    len = ft_strlen(s1);

    ptr = malloc(sizeof(char) * (len + 1));
    if(!ptr) return NULL;

    i = 0;
    while(i < len)
    {
        ptr[i] = s1[i];
        i++;
    }
    ptr[i] = '\0';
    return ptr;

}