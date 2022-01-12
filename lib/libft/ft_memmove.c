#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ch;
	unsigned const char	*cch;

	if (!dst && !src)
		return (dst);
	ch = dst;
	cch = src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			*(ch + len) = *(cch + len);
	}
	return (dst);
}
