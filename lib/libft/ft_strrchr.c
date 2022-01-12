#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	size_t			len;

	chr = c;
	len = ft_strlen(s) + 1;
	while (len)
	{
		if (s[--len] == chr)
			return ((char *)s + len);
	}
	return (0);
}
