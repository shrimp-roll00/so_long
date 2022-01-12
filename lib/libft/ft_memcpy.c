#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ch;
	unsigned const char	*cch;

	if (!dst && !src)
		return (dst);
	ch = dst;
	cch = src;
	while (n--)
		*ch++ = *cch++;
	return (dst);
}
