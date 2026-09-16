#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
    size_t      s1_len;
    size_t      s2_len;
    char        *r;
    size_t      i;


    if(!s1 || !s2) return NULL;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);

    r = (char *)(malloc(sizeof(char) * (s1_len + s2_len + 1)));
    if (!r) return NULL;

    i = 0;

    while(i < s1_len)
    {
        r[i] = s1[i];
        i++;
    }
    i = 0;
    while(i < s2_len)
    {
        r[i + s1_len] = s2[i];
        i++;
    }
    r[i + s1_len] = '\0';
    return r;

}