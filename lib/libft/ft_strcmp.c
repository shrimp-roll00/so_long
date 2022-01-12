#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	n;

	n = ft_strlen(s1);
	while (n--)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else if (!*s1++ || !*s2++)
			return (0);
	}
	return (0);
}
