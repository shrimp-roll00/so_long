#include "libft.h"

static void	handle_u_internal(t_info *info, t_flags *flags, char *us)
{
	int	len;

	len = ft_strlen(us);
	if (flags->precision > len)
		len = flags->precision;
	flags->padding -= len + (flags->sign != 0);
	flags->precision -= ft_strlen(us);
	if (!flags->minus && flags->filler != '0')
		ft_printf_fill_padding(info, flags);
	if (flags->sign)
		info->len += write(1, &flags->sign, 1);
	if (!flags->minus && flags->filler == '0')
		ft_printf_fill_padding(info, flags);
	while (flags->precision-- > 0)
		info->len += write(1, "0", 1);
	info->len += write(1, us, ft_strlen(us));
	if (flags->minus)
		ft_printf_fill_padding(info, flags);
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

int	ft_printf_handle_u(t_info *info, t_flags *flags)
{
	unsigned long long	u;
	char				*us;

	u = lengthen_shorten(info, flags);
	if (!u && !flags->precision && flags->dot)
		us = ft_strdup("");
	else
		us = ft_itoa(u);
	if (!us)
		return (0);
	handle_u_internal(info, flags, us);
	free(us);
	return (1);
}
