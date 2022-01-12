#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*ch;

	ch = s;
	while (n--)
	{
		if (*ch == (unsigned char)c)
			return ((void *)ch);
		ch++;
	}
	return (0);
}
