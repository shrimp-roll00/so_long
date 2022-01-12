#include "so_long.h"

int	main(int argc, char **argv)
{
	t_engine	*engine;

	if (argc != 2)
		so_long_error("two args or else", 0);
	engine = ft_calloc(sizeof(t_engine), 1);
	if (!engine)
		so_long_error("malloc failure", 0);
	so_long_parse(argv[1], engine);
	so_long_initialize(engine);
	so_long_free(engine);
	exit(0);
}
