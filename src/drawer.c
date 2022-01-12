#include "so_long.h"

static void	put_sprite(t_engine *engine, int y, int x, void *from)
{
	int	ax;
	int	ax_tile;
	int	i;
	int	j;

	ax = engine->window.width;
	ax_tile = engine->sprites.tile_size;
	i = y;
	while (i - y < ax_tile)
	{
		j = x;
		while (j - x < ax_tile)
		{
			if (((int *)from)[ax_tile * (i - y) + (j - x)] != -16777216)
				((int *)engine->image.address)[ax * i + j]
					= ((int *)from)[ax_tile * (i - y) + (j - x)];
			j++;
		}
		i++;
	}
}

static void	choose_sprite(t_engine *engine, int i, int j, char coord)
{
	if (coord == '1')
		put_sprite(engine, i, j, engine->sprites.wall.address);
	else if (coord == 'C')
		put_sprite(engine, i, j, engine->sprites.loot.address);
	else if (coord == 'E')
		put_sprite(engine, i, j, engine->sprites.exit.address);
	else if (coord == 'P')
		put_sprite(engine, i, j, engine->sprites.player.address);
	else if (coord == 'L')
		put_sprite(engine, i, j, engine->sprites.enemy.address);
}

static int	check_conditions(t_engine *engine)
{
	mlx_clear_window(engine->mlx, engine->window.window);
	if (engine->game.won)
	{
		mlx_put_image_to_window(engine->mlx, engine->window.window,
			engine->sprites.won.image, engine->window.width / 2 - 96,
			engine->window.height / 2 - 9);
		mlx_string_put(engine->mlx, engine->window.window,
			engine->window.width / 2 - 86, engine->window.height / 2 + 18,
			0x6B8E23, "Press ESC to exit");
		engine->window.won = 1;
		return (1);
	}
	else if (engine->game.lost)
	{
		mlx_put_image_to_window(engine->mlx, engine->window.window,
			engine->sprites.lost.image, engine->window.width / 2 - 96,
			engine->window.height / 2 - 9);
		mlx_string_put(engine->mlx, engine->window.window,
			engine->window.width / 2 - 86, engine->window.height / 2 + 18,
			0x8B0000, "Press ESC to exit");
		engine->window.won = 1;
		return (1);
	}
	else
		return (0);
}

static void	draw_ui(t_engine *engine)
{
	char	*num;

	put_sprite(engine, 0, 0, engine->sprites.moves.address);
	mlx_string_put(engine->mlx, engine->window.window, 96, 32, 0xFFD700,
		num = ft_itoa(engine->game.moves));
	free(num);
	put_sprite(engine, engine->window.height - engine->sprites.tile_size, 0,
		engine->sprites.collected.address);
	mlx_string_put(engine->mlx, engine->window.window, 100,
		100, 0xFFFFFF, num = ft_itoa(engine->game.loot));
	free(num);
}

void	so_long_draw(t_engine *engine)
{
	int		i;
	int		j;
	t_coord	*util;

	if (check_conditions(engine))
		return ;
	util = engine->map.head;
	i = 0;
	while (i < engine->window.height)
	{
		j = 0;
		while (j < engine->window.width)
		{
			put_sprite(engine, i, j, engine->sprites.background.address);
			choose_sprite(engine, i, j, util->letter);
			util = util->next;
			j += engine->sprites.tile_size;
		}
		i += engine->sprites.tile_size;
	}
	draw_ui(engine);
	mlx_put_image_to_window(engine->mlx, engine->window.window,
		engine->image.image, 0, 0);
}
