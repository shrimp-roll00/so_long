#include "libft.h"

static void	handle_i_d_internal(t_info *info, t_flags *flags, char *ds)
{
	int	len;

	len = ft_strlen(ds);
	if (flags->precision > len)
		len = flags->precision;
	flags->padding -= len + (flags->sign != 0);
	flags->precision -= ft_strlen(ds);
	if (!flags->minus && flags->filler != '0')
		ft_printf_fill_padding(info, flags);
	if (flags->sign)
		info->len += write(1, &flags->sign, 1);
	if (!flags->minus && flags->filler == '0')
		ft_printf_fill_padding(info, flags);
	while (flags->precision-- > 0)
		info->len += write(1, "0", 1);
	info->len += write(1, ds, ft_strlen(ds));
	if (flags->minus)
		ft_printf_fill_padding(info, flags);
}

static long long	lengthen_shorten(t_info *info, t_flags *flags)
{
	long long	d;

	if (flags->ll)
		d = va_arg(info->args, long long);
	else if (flags->l)
		d = (long)va_arg(info->args, long);
	else if (flags->h)
		d = (short)va_arg(info->args, int);
	else if (flags->hh)
		d = (char)va_arg(info->args, int);
	else
		d = (int)va_arg(info->args, int);
	return (d);
}

int	ft_printf_handle_i_d(t_info *info, t_flags *flags)
{
	long long	d;
	char		*ds;

	d = lengthen_shorten(info, flags);
	if (d < 0)
	{
		flags->sign = '-';
		d = -d;
	}
	if (!d && !flags->precision && flags->dot)
		ds = ft_strdup("");
	else
		ds = ft_itoa(d);
	if (!ds)
		return (0);
	handle_i_d_internal(info, flags, ds);
	free(ds);
	return (1);
}
