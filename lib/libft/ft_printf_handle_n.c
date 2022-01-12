#include "libft.h"

static void	*lengthen_shorten(t_info *info, t_flags *flags)
{
	void	*n;

	if (flags->ll)
		n = va_arg(info->args, long long *);
	else if (flags->l)
		n = (long *)va_arg(info->args, long *);
	else if (flags->h)
		n = (short *)va_arg(info->args, int *);
	else if (flags->hh)
		n = (char *)va_arg(info->args, int *);
	else
		n = (int *)va_arg(info->args, int *);
	return (n);
}

void	ft_printf_handle_n(t_info *info, t_flags *flags)
{
	void	*n;

	n = lengthen_shorten(info, flags);
	if (flags->ll)
		*(long long *)n = info->len;
	else if (flags->l)
		*(long *)n = info->len;
	else if (flags->h)
		*(short *)n = info->len;
	else if (flags->hh)
		*(char *)n = info->len;
	else
		*(int *)n = info->len;
}
