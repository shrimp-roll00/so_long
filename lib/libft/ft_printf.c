#include "libft.h"

static int	convert_v2(const char *s, t_info *info, t_flags *flags)
{
	if (s[info->i] == 'u')
	{
		if (!ft_printf_handle_u(info, flags))
			return (0);
	}
	else if (s[info->i] == 'x' || s[info->i] == 'X')
	{
		if (!ft_printf_handle_xs(info, flags, s[info->i]))
			return (0);
	}
	else if (s[info->i] == '%')
		ft_printf_handle_c(info, flags, '%');
	else if (s[info->i] == 'n')
		ft_printf_handle_n(info, flags);
	else if (s[info->i] == 'f')
	{
		if (!ft_printf_handle_f(info, flags))
			return (0);
	}
	return (1);
}

static int	convert(const char *s, t_info *info)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	ft_bzero(flags, sizeof(t_flags));
	ft_printf_find_flags(s, info, flags);
	if (s[info->i] == 'c')
		ft_printf_handle_c(info, flags, 0);
	else if (s[info->i] == 's')
		ft_printf_handle_s(info, flags);
	else if (s[info->i] == 'p')
	{
		if (!ft_printf_handle_p(info, flags))
			return (0);
	}
	else if (s[info->i] == 'i' || s[info->i] == 'd')
	{
		if (!ft_printf_handle_i_d(info, flags))
			return (0);
	}
	if (!convert_v2(s, info, flags))
		return (0);
	free(flags);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	t_info	*info;
	int		res;

	info = malloc(sizeof(t_info));
	if (!info)
		return (-1);
	ft_bzero(info, sizeof(t_info));
	info->a_len = ft_strlen(s);
	va_start(info->args, s);
	while (s[info->i])
	{
		if (s[info->i] == '%')
		{
			info->i += 1;
			if (!convert(s, info))
				return (-1);
		}
		else
			info->len += write(1, &s[info->i], 1);
		info->i++;
	}
	va_end(info->args);
	res = info->len;
	free(info);
	return (res);
}
