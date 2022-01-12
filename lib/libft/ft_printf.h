#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <math.h>

# define HEX "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"
# define N "diuxX"
# define F "f"

typedef unsigned long long	t_ull;

typedef struct s_flags
{
	int		padding;
	int		minus;
	int		dot;
	int		precision;
	int		sharp;
	char	sign;
	char	filler;
	int		l;
	int		ll;
	int		h;
	int		hh;
}				t_flags;

typedef struct s_info
{
	va_list		args;
	int			len;
	int			i;
	int			a_len;
}				t_info;

int		ft_printf(const char *s, ...);

void	ft_printf_find_flags(const char *s, t_info *info, t_flags *flags);

void	ft_printf_fill_padding(t_info *info, t_flags *flags);
int		ft_printf_append(char **what, char *with_what);
void	ft_printf_write_wc(wchar_t wc, t_info *info);
char	*ft_printf_basic_malloc(void);

int		ft_printf_numlen(unsigned long long n);

void	ft_printf_handle_s(t_info *info, t_flags *flags);
void	ft_printf_handle_c(t_info *info, t_flags *flags, char what);
int		ft_printf_handle_p(t_info *info, t_flags *flags);
int		ft_printf_handle_i_d(t_info *info, t_flags *flags);
int		ft_printf_handle_u(t_info *info, t_flags *flags);
int		ft_printf_handle_xs(t_info *info, t_flags *flags, char up);
void	ft_printf_handle_n(t_info *info, t_flags *flags);
int		ft_printf_handle_f(t_info *info, t_flags *flags);

char	*ft_itoa_base(unsigned long long n, char *base);
char	*ft_itoa_double(double n, int precision);
int		ft_strcmp(const char *s1, const char *s2);

#endif
