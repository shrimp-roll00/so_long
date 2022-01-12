#include "libft.h"

void	ft_printf_fill_padding(t_info *info, t_flags *flags)
{
	while (flags->padding-- > 0)
		info->len += write(1, &flags->filler, 1);
}

int	ft_printf_append(char **what, char *what_with)
{
	char	*temp;

	temp = ft_strjoin(*what, what_with);
	if (!temp)
		return (0);
	free(what_with);
	free(*what);
	*what = temp;
	return (1);
}

char	*ft_printf_basic_malloc(void)
{
	char	*s;

	s = malloc(1);
	if (!s)
		return (0);
	s[0] = 0;
	return (s);
}
