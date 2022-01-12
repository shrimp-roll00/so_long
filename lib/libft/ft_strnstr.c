#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	str;

	if (!*needle)
		return ((char *)haystack);
	str = ft_strlen(needle);
	while (len)
	{
		if (!*haystack || str > len--)
			return (0);
		if (!ft_strncmp(haystack, needle, str))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
