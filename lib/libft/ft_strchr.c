#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	if (!c)
		return ((char *)s + ft_strlen(s));
	chr = c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		else if (!*s++)
			return (0);
	}
	return (0);
}
