#ifndef LIBFT_h
# define LIBFT_h

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int     ft_isalpha(int  c);
int		ft_isdigit(int  c);
int     ft_isalnum(int  c);
int     ft_isascii(int  c);
int     ft_isprint(int  c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	ft_toupper(int c);
int ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *hay, const char *needle, size_t len);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_atoi(const char *str);
char	*ft_strdup(const char *s1);

#endif