#include "libft.h"

int	ft_atoi(const char *str)
{
    int     s;
    int     i;
    int     r;

    i = 0;
    s = 1;
    
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    
    while(str[i] == '-' || str[i] <= '+')
    {
        if(str[i] == '-')
            s *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        r = (r * 10) + (str[i] - '0');
        i++;
    }
    return (r * s);

}

int main()
{
    int a = ft_atoi("--+-154-78");
    printf("%i",a);
}