#include "so_long.h"

static void	free_player(t_engine *engine)
{
	if (engine->sprites.player.angel1)
		mlx_destroy_image(engine->mlx, engine->sprites.player.angel1);
	if (engine->sprites.player.angel2)
		mlx_destroy_image(engine->mlx, engine->sprites.player.angel2);
	if (engine->sprites.player.angel3)
		mlx_destroy_image(engine->mlx, engine->sprites.player.angel3);
	if (engine->sprites.player.angel4)
		mlx_destroy_image(engine->mlx, engine->sprites.player.angel4);
	if (engine->sprites.player.angel5)
		mlx_destroy_image(engine->mlx, engine->sprites.player.angel5);
	if (engine->sprites.player.angel6)
		mlx_destroy_image(engine->mlx, engine->sprites.player.angel6);
	if (engine->sprites.player.angel7)
		mlx_destroy_image(engine->mlx, engine->sprites.player.angel7);
	if (engine->sprites.player.angel8)
		mlx_destroy_image(engine->mlx, engine->sprites.player.angel8);
}

static void	free_enemy(t_engine *engine)
{
	if (engine->sprites.enemy.ghoul1)
		mlx_destroy_image(engine->mlx, engine->sprites.enemy.ghoul1);
	if (engine->sprites.enemy.ghoul2)
		mlx_destroy_image(engine->mlx, engine->sprites.enemy.ghoul2);
	if (engine->sprites.enemy.ghoul3)
		mlx_destroy_image(engine->mlx, engine->sprites.enemy.ghoul3);
	if (engine->sprites.enemy.ghoul4)
		mlx_destroy_image(engine->mlx, engine->sprites.enemy.ghoul4);
	if (engine->sprites.enemy.ghoul5)
		mlx_destroy_image(engine->mlx, engine->sprites.enemy.ghoul5);
	if (engine->sprites.enemy.ghoul6)
		mlx_destroy_image(engine->mlx, engine->sprites.enemy.ghoul6);
	if (engine->sprites.enemy.ghoul7)
		mlx_destroy_image(engine->mlx, engine->sprites.enemy.ghoul7);
	if (engine->sprites.enemy.ghoul8)
		mlx_destroy_image(engine->mlx, engine->sprites.enemy.ghoul8);
}

static void	free_ui(t_engine *engine)
{
	if (engine->sprites.moves.image)
		mlx_destroy_image(engine->mlx, engine->sprites.moves.image);
	if (engine->sprites.collected.image)
		mlx_destroy_image(engine->mlx, engine->sprites.collected.image);
	if (engine->sprites.won.image)
		mlx_destroy_image(engine->mlx, engine->sprites.won.image);
	if (engine->sprites.lost.image)
		mlx_destroy_image(engine->mlx, engine->sprites.lost.image);
}

void	so_long_free(t_engine *engine)
{
	if (engine)
	{
		if (engine->image.image)
			mlx_destroy_image(engine->mlx, engine->image.image);
		if (engine->sprites.background.image)
			mlx_destroy_image(engine->mlx, engine->sprites.background.image);
		if (engine->sprites.wall.image)
			mlx_destroy_image(engine->mlx, engine->sprites.wall.image);
		if (engine->sprites.loot.image)
			mlx_destroy_image(engine->mlx, engine->sprites.loot.image);
		if (engine->sprites.exit.image)
			mlx_destroy_image(engine->mlx, engine->sprites.exit.image);
		free_player(engine);
		free_enemy(engine);
		free_ui(engine);
		if (engine->window.window)
			mlx_destroy_window(engine->mlx, engine->window.window);
		free(engine->mlx);
		so_long_free_coords(engine->map.head);
		free(engine);
	}
}
