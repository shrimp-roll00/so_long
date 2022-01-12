#include "so_long.h"

static void	mover_util(t_engine *engine, t_coord *player, t_coord *new)
{
	if (new->letter == 'C')
		engine->game.loot -= 1;
	else if (new->letter == 'L')
	{
		engine->game.lost = 1;
		return ;
	}
	else if (new->letter == '1' || (new->letter == 'E' && engine->game.loot))
		return ;
	else if (new->letter == 'E' && !engine->game.loot)
		engine->game.won = 1;
	new->letter = 'P';
	player->letter = '0';
	engine->game.moves += 1;
}

void	so_long_move_up(t_engine *engine)
{
	t_coord	*player;
	t_coord	*new;

	player = engine->map.head;
	while (player && player->letter != 'P')
		player = player->next;
	new = engine->map.head;
	while (new)
	{
		if (new->x == player->x && new->y == player->y - 1)
			break ;
		new = new->next;
	}
	mover_util(engine, player, new);
}

void	so_long_move_down(t_engine *engine)
{
	t_coord	*player;
	t_coord	*new;

	player = engine->map.head;
	while (player && player->letter != 'P')
		player = player->next;
	new = engine->map.head;
	while (new)
	{
		if (new->x == player->x && new->y == player->y + 1)
			break ;
		new = new->next;
	}
	mover_util(engine, player, new);
}

void	so_long_move_right(t_engine *engine)
{
	t_coord	*player;
	t_coord	*new;

	player = engine->map.head;
	while (player && player->letter != 'P')
		player = player->next;
	new = engine->map.head;
	while (new)
	{
		if (new->x == player->x + 1 && new->y == player->y)
			break ;
		new = new->next;
	}
	mover_util(engine, player, new);
}

void	so_long_move_left(t_engine *engine)
{
	t_coord	*player;
	t_coord	*new;

	player = engine->map.head;
	while (player && player->letter != 'P')
		player = player->next;
	new = engine->map.head;
	while (new)
	{
		if (new->x == player->x - 1 && new->y == player->y)
			break ;
		new = new->next;
	}
	mover_util(engine, player, new);
}
