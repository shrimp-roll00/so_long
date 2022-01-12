#include "libft.h"

static double	pow_pow(int mult)
{
	double	res;

	res = 1;
	while (mult-- > 0)
		res *= 10;
	return (res);
}

static t_ull	check_rounding(double a, int p, unsigned long long *bef)
{
	char				*temp;
	unsigned long long	res;

	a *= pow_pow(p);
	a += 0.5;
	a /= pow_pow(p);
	res = 0;
	while (p-- > 0)
	{
		a *= 10;
		temp = ft_itoa(a);
		if (ft_strlen(temp) > 1)
		{
			a = 0;
			*bef += 1;
			free(temp);
		}
		else
			free(temp);
		res = res * 10 + a;
		a -= (unsigned long long)a;
	}
	return (res);
}

static int	handle_after(char **str, double a, int p, unsigned long long *bef)
{
	double				temp;
	int					zeros;
	unsigned long long	res;

	temp = a;
	zeros = 0;
	res = check_rounding(a, p, bef);
	p -= ft_printf_numlen(res);
	while ((unsigned long long)(temp + 1e-5) == 0 && p-- >= 0)
	{
		zeros++;
		temp *= 10;
	}
	if (!zeros && ft_printf_numlen(res) < p)
		zeros = p + ft_printf_numlen(res);
	while (--zeros > 0)
	{
		if (!ft_printf_append(str, ft_strdup("0")))
			return (0);
	}
	if (!ft_printf_append(str, ft_itoa(res)))
		return (0);
	return (1);
}

static int	compose(unsigned long long before, double after, char **str, int p)
{
	char	*after_s;

	after_s = ft_printf_basic_malloc();
	if (!after_s)
		return (0);
	if (!handle_after(&after_s, after, p, &before))
		return (0);
	if (!ft_printf_append(str, ft_itoa(before)))
		return (0);
	if (p > 0)
	{
		if (!ft_printf_append(str, ft_strdup(".")))
			return (0);
		if (!ft_printf_append(str, after_s))
			return (0);
	}
	else
		free(after_s);
	return (1);
}

char	*ft_itoa_double(double n, int p)
{
	char				*str;
	unsigned long long	before;
	double				after;

	if (n < 0)
		n = -n;
	str = ft_printf_basic_malloc();
	if (!str)
		return (0);
	before = (unsigned long long)n;
	after = n - before;
	if (((after == 0.5 && before % 2 == 1) || after > 0.5) && p == 0)
	{
		before++;
		after = 0;
	}
	if (!compose(before, after, &str, p))
		return (0);
	return (str);
}
