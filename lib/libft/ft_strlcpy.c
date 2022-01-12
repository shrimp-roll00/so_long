#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_l;

	src_l = ft_strlen(src);
	if (!dstsize)
		return (src_l);
	if (src_l >= dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	else
	{
		ft_memcpy(dst, src, src_l + 1);
	}
	return (src_l);
}
