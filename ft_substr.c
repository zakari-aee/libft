#include  "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    
    size_t s_len;
    size_t i;
    char *r;


    if(!s) return NULL;

    s_len = ft_strlen(s);
    
    if(start >= s_len) return ft_strdup("");

    if(len > s_len - start)
        len = s_len - start;
    
    r = (char *)(malloc(sizeof(char) * (len + 1)));
    if(!r) return NULL;

    i = 0;
    while(i < len)
    {
        r[i] = s[start + i];
        i++;
    }
    r[i] = '\0';
    return r;
}