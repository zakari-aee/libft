#include "libft.h"

static size_t count_words(char const *s, char c)
{
    size_t count = 0;
    while (*s)
    {
        while (*s && *s == c)
            s++;
        if (*s)
            count++;

        while (*s && *s != c)
            s++;
    }
    return count;
}

static char **free_words(char **result, size_t count)
{
    while (count > 0)
        free(result[--count]);
    free(result);
    return NULL;
}

static char *word_dup(char const *str, char c)
{
    size_t i;
    char *word;

    while(str[i] && str[i] != c)
        i++;
    word = malloc(sizeof(char) * (i + 1));
    if(!word) return NULL;
    i = 0;
    while(str[i] && str[i] != c)
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return word;
}

char    **ft_split(char const *s, char c)
{
    size_t      i;
    size_t      j;
    char        **result;
    if(!*s) return NULL;

    i = 0;
    j = 0;
    result = malloc((count_words(s,c) + 1) * sizeof(char));
    if(!result) return NULL;

    while(s[i])
    {
        if(s[i] != c)
        {
            result[j] = word_dup(&s[i],c);
            if(!result[j]) return (free_words(result,j));
                j++;
            while(s[i] && s[i] != c)
                i++;
        }
        else
            i++;
    }
    result[j] = NULL;
    return result;
}	