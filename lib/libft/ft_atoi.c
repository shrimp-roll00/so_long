#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	mod;

	res = 0;
	mod = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		mod = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	if (!ft_isdigit(*nptr))
		return (0);
	while (ft_isdigit(*nptr) && *nptr)
		res = (res * 10) + (*nptr++ - 48);
	return (res * mod);
}
