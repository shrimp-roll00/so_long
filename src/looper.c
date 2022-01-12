#include "so_long.h"

static void	player_loop(t_engine *engine)
{
	static int	loop;
	int			u;
	void		*image;

	image = engine->sprites.player.angel1;
	if (loop > 7 && loop <= 14)
		image = engine->sprites.player.angel2;
	else if (loop > 14 && loop <= 21)
		image = engine->sprites.player.angel3;
	else if (loop > 21 && loop <= 28)
		image = engine->sprites.player.angel4;
	else if (loop > 28 && loop <= 35)
		image = engine->sprites.player.angel5;
	else if (loop > 35 && loop <= 42)
		image = engine->sprites.player.angel6;
	else if (loop > 42 && loop <= 49)
		image = engine->sprites.player.angel7;
	else if (loop > 49 && loop <= 56)
		image = engine->sprites.player.angel8;
	else if (loop > 56)
		loop = 0;
	engine->sprites.player.address = mlx_get_data_addr(image, &u, &u, &u);
	loop++;
}

static void	enemy_loop(t_engine *engine)
{
	static int	loop;
	int			u;
	void		*image;

	image = engine->sprites.enemy.ghoul1;
	if (loop > 10 && loop <= 20)
		image = engine->sprites.enemy.ghoul2;
	else if (loop > 20 && loop <= 30)
		image = engine->sprites.enemy.ghoul3;
	else if (loop > 30 && loop <= 40)
		image = engine->sprites.enemy.ghoul4;
	else if (loop > 40 && loop <= 50)
		image = engine->sprites.enemy.ghoul5;
	else if (loop > 50 && loop <= 60)
		image = engine->sprites.enemy.ghoul6;
	else if (loop > 60 && loop <= 70)
		image = engine->sprites.enemy.ghoul7;
	else if (loop > 70 && loop <= 80)
		image = engine->sprites.enemy.ghoul8;
	else if (loop > 80)
		loop = 0;
	engine->sprites.enemy.address = mlx_get_data_addr(image, &u, &u, &u);
	loop++;
}

int	so_long_main_loop(t_engine *engine)
{
	char	*num;

	if (engine->window.won || engine->window.lost)
		return (0);
	so_long_draw(engine);
	player_loop(engine);
	enemy_loop(engine);
	if (!engine->window.won && !engine->window.lost)
	{
		mlx_string_put(engine->mlx, engine->window.window, 80, 23, 0xFFFFFF,
			num = ft_itoa(engine->game.moves));
		free(num);
		mlx_string_put(engine->mlx, engine->window.window, 80,
			engine->window.height - 41, 0xFFFFFF,
			num = ft_itoa(engine->game.loot));
		free(num);
	}
	return (0);
}
