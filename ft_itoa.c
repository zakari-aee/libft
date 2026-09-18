#include "libft.h"

static int	count_digits(long n)
{
    int     len;

    len = 1;
    if (n < 0)
	{
		len++;
		n = -n;
	}
    while(n >= 10)
    {
        n /= 10;
        len++;
    }
    return len;
}

char	*ft_itoa(int n)
{
    char    *r;
    long    z;
    int     len;

    z = n;
    
    len = count_digits(z);
    r = (char *)malloc(sizeof(char) * (len + 1));

    if(!r) return NULL;
    r[len] = '\0';
    if(z < 0)
    {
        r[0] = '-';
        z = -z;
    }
    len--;
    while(z >= 10)
    {
        r[len] = (z % 10) + '0';
        z /= 10;
        len--;
    }
    r[len] = z + '0';
    return r;
}

int main()
{
    printf("%s",ft_itoa(-15));
    return 0;
}