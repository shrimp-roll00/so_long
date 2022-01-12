#include "libft.h"

static void	handle_ws(t_info *info)
{
	wchar_t	*ws;

	ws = va_arg(info->args, wchar_t *);
	if (!ws)
		ws = L"(null)";
	while (*ws)
		ft_printf_write_wc(*ws++, info);
}

void	ft_printf_handle_s(t_info *info, t_flags *flags)
{
	char	*s;
	int		len;

	if (flags->l)
	{
		handle_ws(info);
		return ;
	}
	s = va_arg(info->args, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (flags->dot && flags->precision < len && flags->precision >= 0 && s)
		len = flags->precision;
	flags->padding -= len;
	if (!flags->minus)
		ft_printf_fill_padding(info, flags);
	info->len += write(1, s, len);
	if (flags->minus)
		ft_printf_fill_padding(info, flags);
}
