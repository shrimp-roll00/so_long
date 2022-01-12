#include "libft.h"

char	*ft_strjoin_free_first(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	res = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (0);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = 0;
	free(s1);
	return (res);
}
