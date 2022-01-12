#include "libft.h"

int	ft_printf_handle_p(t_info *info, t_flags *flags)
{
	unsigned long long	p;
	char				*ps;
	int					len;

	p = va_arg(info->args, unsigned long long);
	ps = ft_itoa_base(p, HEX);
	if (!ps)
		return (0);
	len = ft_strlen(ps);
	if (flags->precision == 0 && flags->dot && !p)
		len = 0;
	flags->padding -= len + 2;
	if (!flags->minus)
		ft_printf_fill_padding(info, flags);
	info->len += write(1, "0x", 2);
	info->len += write(1, ps, len);
	if (flags->minus)
		ft_printf_fill_padding(info, flags);
	free(ps);
	return (1);
}
