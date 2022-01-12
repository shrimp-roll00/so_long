#include "libft.h"

static void	handle_f_internal(t_info *info, t_flags *f, char *fs, int inf)
{
	int	len;

	if (inf)
		f->filler = ' ';
	len = ft_strlen(fs);
	f->padding -= len + (f->sign != 0) + (f->sharp && !ft_strchr(fs, '.'));
	f->precision -= len;
	if (!f->minus && f->filler != '0')
		ft_printf_fill_padding(info, f);
	if (f->sign)
		info->len += write(1, &f->sign, 1);
	if (!f->minus && f->filler == '0')
		ft_printf_fill_padding(info, f);
	info->len += write(1, fs, ft_strlen(fs));
	if (f->sharp && !ft_strchr(fs, '.'))
		info->len += write(1, ".", 1);
	if (f->minus)
		ft_printf_fill_padding(info, f);
}

static char	*check_inf(double f, t_flags *flags, int *inf)
{
	char	*fs;

	if (f == INFINITY)
	{
		fs = ft_strdup("inf");
		*inf = 1;
	}
	else if (f == -INFINITY)
	{
		fs = ft_strdup("-inf");
		*inf = 1;
	}
	else if (f != f)
	{
		fs = ft_strdup("nan");
		*inf = 1;
	}
	else
	{
		if (flags->dot && flags->precision >= 0)
			fs = ft_itoa_double(f, flags->precision);
		else
			fs = ft_itoa_double(f, 6);
	}
	return (fs);
}

int	ft_printf_handle_f(t_info *info, t_flags *flags)
{
	double		f;
	char		*fs;
	int			inf;

	f = va_arg(info->args, double);
	if (f < 0 || 1 / f < 0)
	{
		flags->sign = '-';
		f = -f;
	}
	inf = 0;
	fs = check_inf(f, flags, &inf);
	if (!fs)
		return (0);
	handle_f_internal(info, flags, fs, inf);
	free(fs);
	return (1);
}
