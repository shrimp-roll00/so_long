#include "libft.h"

static void	length_flags(const char *s, t_info *info, t_flags *flags, char c)
{
	if (s[info->i + 1] == c)
	{
		if (c == 'h')
			flags->hh = 1;
		else if (c == 'l')
			flags->ll = 1;
		info->i++;
	}
	else
	{
		if (c == 'h')
			flags->h = 1;
		else if (c == 'l')
			flags->l = 1;
	}
}

static void	search(const char *s, t_info *info, t_flags *flags)
{
	while (1)
	{
		if (s[info->i] == '-' && info->i < info->a_len)
			flags->minus = 1;
		else if (s[info->i] == '+' && info->i < info->a_len)
			flags->sign = '+';
		else if (s[info->i] == ' ' && info->i < info->a_len)
		{
			if (!flags->sign)
				flags->sign = ' ';
		}
		else if (s[info->i] == '0' && info->i < info->a_len)
			flags->filler = '0';
		else if (s[info->i] == 'l' && info->i < info->a_len)
			length_flags(s, info, flags, 'l');
		else if (s[info->i] == 'h' && info->i < info->a_len)
			length_flags(s, info, flags, 'h');
		else if (s[info->i] == '#' && info->i < info->a_len)
			flags->sharp = 1;
		else if (s[info->i] != '\'')
			break ;
		info->i++;
	}
}

static void	padding(const char *s, t_info *info, t_flags *flags)
{
	if (ft_isdigit(s[info->i]))
	{
		while (ft_isdigit(s[info->i]))
		{
			flags->padding = 10 * flags->padding + (s[info->i] - '0');
			info->i++;
		}
	}
	else if (s[info->i] == '*')
	{
		flags->padding = va_arg(info->args, int);
		info->i++;
		if (flags->padding < 0)
		{
			flags->minus = 1;
			flags->padding = -flags->padding;
		}
	}
}

static void	precision(const char *s, t_info *info, t_flags *flags)
{
	if (s[info->i] == '.')
	{
		info->i++;
		if (ft_isdigit(s[info->i]))
		{
			flags->precision = 0;
			while (ft_isdigit(s[info->i]))
			{
				flags->precision = 10 * flags->precision + (s[info->i] - '0');
				info->i++;
			}
		}
		else if (s[info->i] == '*')
		{
			flags->precision = va_arg(info->args, int);
			info->i++;
		}
		flags->dot = 1;
	}
}

void	ft_printf_find_flags(const char *s, t_info *info, t_flags *f)
{
	f->filler = ' ';
	search(s, info, f);
	padding(s, info, f);
	precision(s, info, f);
	search(s, info, f);
	if (ft_strchr(N, s[info->i]) && ((f->dot && f->precision >= 0) || f->minus))
		f->filler = ' ';
	if (ft_strchr(F, s[info->i]) && f->minus)
		f->filler = ' ';
	if (s[info->i] == '%' && f->minus)
		f->filler = ' ';
}
