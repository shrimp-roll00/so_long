#include "libft.h"

static int 	numlen(unsigned long long n, int del)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= del;
		count++;
	}
	return (count);
}

static void	reverse(char *hey)
{
	char	*util;
	char	tmp;

	util = hey + ft_strlen(hey) - 1;
	if (*hey == '-')
		hey++;
	while (util > hey)
	{
		tmp = *util;
		*util-- = *hey;
		*hey++ = tmp;
	}
}

char	*ft_itoa_base(unsigned long long n, char *base)
{
	char	*str;
	char	*res;
	int		len;

	len = ft_strlen(base);
	str = malloc(numlen(n, len) + 1);
	res = str;
	if (!str)
		return (0);
	if (n == 0)
		*str++ = '0';
	while (n != 0)
	{
		*str++ = base[n % len];
		n /= len;
	}
	*str = 0;
	reverse(res);
	return (res);
}
