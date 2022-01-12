#include "so_long.h"

void	so_long_init_player(t_engine *engine)
{
	int	u;

	engine->sprites.player.angel1 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/angel1.xpm", &u, &u);
	engine->sprites.player.angel2 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/angel2.xpm", &u, &u);
	engine->sprites.player.angel3 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/angel3.xpm", &u, &u);
	engine->sprites.player.angel4 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/angel4.xpm", &u, &u);
	engine->sprites.player.angel5 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/angel5.xpm", &u, &u);
	engine->sprites.player.angel6 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/angel6.xpm", &u, &u);
	engine->sprites.player.angel7 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/angel7.xpm", &u, &u);
	engine->sprites.player.angel8 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/angel8.xpm", &u, &u);
	if (!engine->sprites.player.angel1 || !engine->sprites.player.angel2
		|| !engine->sprites.player.angel3 || !engine->sprites.player.angel4
		|| !engine->sprites.player.angel5 || !engine->sprites.player.angel6
		|| !engine->sprites.player.angel7 || !engine->sprites.player.angel8)
		so_long_error("malloc failure", engine);
	engine->sprites.player.address
		= mlx_get_data_addr(engine->sprites.player.angel1, &u, &u, &u);
}

void	so_long_init_enemy(t_engine *engine)
{
	int	u;

	engine->sprites.enemy.ghoul1 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/ghoul1.xpm", &u, &u);
	engine->sprites.enemy.ghoul2 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/ghoul2.xpm", &u, &u);
	engine->sprites.enemy.ghoul3 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/ghoul3.xpm", &u, &u);
	engine->sprites.enemy.ghoul4 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/ghoul4.xpm", &u, &u);
	engine->sprites.enemy.ghoul5 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/ghoul5.xpm", &u, &u);
	engine->sprites.enemy.ghoul6 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/ghoul6.xpm", &u, &u);
	engine->sprites.enemy.ghoul7 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/ghoul7.xpm", &u, &u);
	engine->sprites.enemy.ghoul8 = mlx_xpm_file_to_image(engine->mlx,
			"res/textures/ghoul8.xpm", &u, &u);
	if (!engine->sprites.enemy.ghoul1 || !engine->sprites.enemy.ghoul2
		|| !engine->sprites.enemy.ghoul3 || !engine->sprites.enemy.ghoul4
		|| !engine->sprites.enemy.ghoul5 || !engine->sprites.enemy.ghoul6
		|| !engine->sprites.enemy.ghoul7 || !engine->sprites.enemy.ghoul8)
		so_long_error("malloc failure", engine);
	engine->sprites.enemy.address
		= mlx_get_data_addr(engine->sprites.enemy.ghoul1, &u, &u, &u);
}
