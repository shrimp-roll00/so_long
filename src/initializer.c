#include "so_long.h"

static int	quit(t_engine *engine)
{
	so_long_free(engine);
	exit(0);
}

static int	keychain(int keycode, t_engine *engine)
{
	if (keycode == ESC)
		quit(engine);
	else if (keycode == W)
		so_long_move_up(engine);
	else if (keycode == A)
		so_long_move_left(engine);
	else if (keycode == S)
		so_long_move_down(engine);
	else if (keycode == D)
		so_long_move_right(engine);
	return (1);
}

static void	init_static(t_engine *engine)
{
	int	u;

	engine->sprites.background.image = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/background.xpm", &engine->sprites.background.width,
			&engine->sprites.background.height);
	engine->sprites.wall.image = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/wall.xpm", &engine->sprites.wall.width,
			&engine->sprites.wall.height);
	engine->sprites.exit.image = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/exit.xpm", &engine->sprites.exit.width,
			&engine->sprites.exit.height);
	engine->sprites.loot.image = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/loot.xpm", &engine->sprites.loot.width,
			&engine->sprites.loot.height);
	if (!engine->sprites.background.image || !engine->sprites.wall.image
		|| !engine->sprites.exit.image || !engine->sprites.loot.image)
		so_long_error("malloc failure", engine);
	engine->sprites.background.address
		= mlx_get_data_addr(engine->sprites.background.image, &u, &u, &u);
	engine->sprites.wall.address
		= mlx_get_data_addr(engine->sprites.wall.image, &u, &u, &u);
	engine->sprites.exit.address
		= mlx_get_data_addr(engine->sprites.exit.image, &u, &u, &u);
	engine->sprites.loot.address
		= mlx_get_data_addr(engine->sprites.loot.image, &u, &u, &u);
}

static void	init_ui(t_engine *engine)
{
	int	u;

	engine->sprites.moves.image = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/moves.xpm", &engine->sprites.moves.width,
			&engine->sprites.moves.height);
	engine->sprites.collected.image = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/collected.xpm", &engine->sprites.collected.width,
			&engine->sprites.collected.height);
	engine->sprites.won.image = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/won.xpm", &engine->sprites.won.width,
			&engine->sprites.won.height);
	engine->sprites.lost.image = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/lost.xpm", &engine->sprites.lost.width,
			&engine->sprites.lost.height);
	if (!engine->sprites.won.image || !engine->sprites.lost.image
		|| !engine->sprites.moves.image || !engine->sprites.collected.image)
		so_long_error("malloc failure", engine);
	engine->sprites.moves.address
		= mlx_get_data_addr(engine->sprites.moves.image, &u, &u, &u);
	engine->sprites.collected.address
		= mlx_get_data_addr(engine->sprites.collected.image, &u, &u, &u);
	engine->sprites.won.address
		= mlx_get_data_addr(engine->sprites.won.image, &u, &u, &u);
	engine->sprites.lost.address
		= mlx_get_data_addr(engine->sprites.lost.image, &u, &u, &u);
}

void	so_long_initialize(t_engine *engine)
{
	int	u;

	engine->mlx = mlx_init();
	if (!engine->mlx)
		so_long_error("malloc failure", engine);
	engine->sprites.tile_size = 64;
	engine->window.width = engine->map.width * engine->sprites.tile_size;
	engine->window.height = engine->map.height * engine->sprites.tile_size;
	init_static(engine);
	init_ui(engine);
	so_long_init_player(engine);
	so_long_init_enemy(engine);
	engine->window.window = mlx_new_window(engine->mlx, engine->window.width,
			engine->window.height, "dark souls IV");
	if (!engine->window.window)
		so_long_error("malloc failure", engine);
	engine->image.image = mlx_new_image(engine->mlx, engine->window.width,
			engine->window.height);
	if (!engine->image.image)
		so_long_error("malloc failure", engine);
	engine->image.address = mlx_get_data_addr(engine->image.image, &u, &u, &u);
	mlx_hook(engine->window.window, PRESS, 0, keychain, engine);
	mlx_hook(engine->window.window, DESTROY, 0, quit, engine);
	mlx_loop_hook(engine->mlx, so_long_main_loop, engine);
	mlx_loop(engine->mlx);
}
