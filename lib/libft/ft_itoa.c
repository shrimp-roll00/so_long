#include "libft.h"

int 	ft_printf_numlen(unsigned long long n)
{
	int	sky;

	sky = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		sky++;
	}
	return (sky);
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

char	*ft_itoa(long long n)
{
	char		*str;
	char		*res;
	long long	l_n;

	l_n = n;
	str = malloc(ft_printf_numlen(n) + 1);
	res = str;
	if (!str)
		return (0);
	if (n < 0)
	{
		*str++ = '-';
		l_n = -l_n;
	}
	if (l_n == 0)
		*str++ = '0';
	while (l_n != 0)
	{
		*str++ = l_n % 10 + '0';
		l_n /= 10;
	}
	*str = 0;
	reverse(res);
	return (res);
}
