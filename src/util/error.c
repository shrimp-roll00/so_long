#include "so_long.h"

void	so_long_error(char *message, t_engine *engine)
{
	so_long_free(engine);
	ft_printf("\e[1;31mError: %s.\e[0m\n", message);
	exit(1);
}
