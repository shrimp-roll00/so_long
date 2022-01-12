#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*res;

	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (0);
	if (n > ft_strlen(s))
		ft_strlcpy(res, s, ft_strlen(s) + 1);
	else
		ft_strlcpy(res, s, n + 1);
	return (res);
}
