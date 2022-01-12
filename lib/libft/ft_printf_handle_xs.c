#include "libft.h"

static int	handle_xs_sharp(t_flags *flags, char up, int z, int before)
{
	int	ret;

	ret = 0;
	if (flags->sharp && z && flags->filler == '0' && before)
	{
		ret += write(1, "0", 1);
		ret += write(1, &up, 1);
	}
	else if (flags->sharp && z && flags->filler != '0' && !before)
	{
		ret += write(1, "0", 1);
		ret += write(1, &up, 1);
	}
	else
		return (0);
	return (ret);
}

static void	handle_xs_internal(t_info *info, t_flags *f, char *xs, char up)
{
	int	len;
	int	z;

	len = ft_strlen(xs);
	z = ft_strcmp(xs, "0");
	if (f->precision > len)
		len = f->precision;
	f->padding -= len + (f->sign != 0) + ((f->sharp != 0) * (z != 0) * 2);
	f->precision -= ft_strlen(xs);
	if (!f->minus && f->filler != '0')
		ft_printf_fill_padding(info, f);
	if (f->sign)
		info->len += write(1, &f->sign, 1);
	info ->len += handle_xs_sharp(f, up, z, 1);
	if (!f->minus && f->filler == '0')
		ft_printf_fill_padding(info, f);
	info->len += handle_xs_sharp(f, up, z, 0);
	while (f->precision-- > 0)
		info->len += write(1, "0", 1);
	info->len += write(1, xs, ft_strlen(xs));
	if (f->minus)
		ft_printf_fill_padding(info, f);
}

static unsigned long long	lengthen_shorten(t_info *info, t_flags *flags)
{
	unsigned long long	u;

	if (flags->ll)
		u = va_arg(info->args, unsigned long long);
	else if (flags->l)
		u = (unsigned long)va_arg(info->args, unsigned long);
	else if (flags->h)
		u = (unsigned short)va_arg(info->args, unsigned int);
	else if (flags->hh)
		u = (unsigned char)va_arg(info->args, unsigned int);
	else
		u = (unsigned int)va_arg(info->args, unsigned int);
	return (u);
}

int	ft_printf_handle_xs(t_info *info, t_flags *flags, char up)
{
	unsigned long long	x;
	char				*xs;

	x = lengthen_shorten(info, flags);
	if (!x && !flags->precision && flags->dot)
		xs = ft_strdup("");
	else
	{
		if (up == 'X')
			xs = ft_itoa_base(x, HEXUP);
		else
			xs = ft_itoa_base(x, HEX);
	}
	if (!xs)
		return (0);
	handle_xs_internal(info, flags, xs, up);
	free(xs);
	return (1);
}
