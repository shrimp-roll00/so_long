#include "libft.h"

static void	write_wc_v2(wchar_t wc, t_info *info)
{
	char	ws[4];

	ws[0] = ((wc >> 18) + 240);
	ws[1] = (((wc >> 12) & 63) + 128);
	ws[2] = (((wc >> 6) & 63) + 128);
	ws[3] = ((wc & 63) + 128);
	info->len += write(1, ws, 4);
}

void	ft_printf_write_wc(wchar_t wc, t_info *info)
{
	char	ws[3];

	if (wc >= 0 && wc <= 255)
		info->len += write(1, &wc, 1);
	else if (wc >= 128 && wc <= 2047)
	{
		ws[0] = ((wc >> 6) + 192);
		ws[1] = ((wc & 63) + 128);
		info->len += write(1, ws, 2);
	}
	else if (wc >= 2048 && wc <= 65535)
	{
		ws[0] = ((wc >> 12) + 224);
		ws[1] = (((wc >> 6) & 63) + 128);
		ws[2] = ((wc & 63) + 128);
		info->len += write(1, ws, 3);
	}
	else if (wc >= 65536 && wc <= 1114111)
		write_wc_v2(wc, info);
}

void	ft_printf_handle_c(t_info *info, t_flags *flags, char what)
{
	wchar_t	c;

	if (!what)
	{
		if (flags->l)
			c = va_arg(info->args, wint_t);
		else
			c = (unsigned char) va_arg(info->args, int);
	}
	else
		c = what;
	flags->padding -= 1;
	if (!flags->minus)
		ft_printf_fill_padding(info, flags);
	ft_printf_write_wc(c, info);
	if (flags->minus)
		ft_printf_fill_padding(info, flags);
}
