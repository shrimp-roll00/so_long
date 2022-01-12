#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s1) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (0);
	ft_strlcpy(res, s1, len);
	return (res);
}
