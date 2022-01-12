#include "so_long.h"

static void	check_borders(t_engine *engine)
{
	t_coord	*util;

	util = engine->map.head;
	while (util)
	{
		if ((util->x == 0 || util->x == engine->map.width - 1 || util->y == 0
				|| util->y == engine->map.height - 1) && util->letter != '1')
			so_long_error("the map ain't surrounded by walls", engine);
		util = util->next;
	}
}

static void	check_chars(t_engine *engine)
{
	t_coord	*util;
	int		players;
	int		exits;

	util = engine->map.head;
	players = 0;
	exits = 0;
	while (util)
	{
		if (!ft_strchr(VALID_CHARS, util->letter))
			so_long_error("weird chars in the map", engine);
		if (util->letter == 'P')
			players++;
		else if (util->letter == 'C')
			engine->game.loot += 1;
		else if (util->letter == 'E')
			exits++;
		util = util->next;
	}
	if (players != 1)
		so_long_error("more/less than one player", engine);
	if (engine->game.loot < 1)
		so_long_error("no collectibles in the map", engine);
	if (exits < 1)
		so_long_error("no exits in the map", engine);
}

void	so_long_validate(t_engine *engine)
{
	check_borders(engine);
	check_chars(engine);
}
