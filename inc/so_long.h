#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define VALID_CHARS "01CEPL"

# define PRESS 02
# define DESTROY 17

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_coord
{
	char			letter;
	int				x;
	int				y;
	struct s_coord	*next;
}				t_coord;

typedef struct s_map
{
	t_coord	*head;
	int		width;
	int		height;
}				t_map;

typedef struct s_game
{
	int					loot;
	int					lost;
	int					won;
	unsigned long long	moves;
}				t_game;

typedef struct s_window
{
	void	*window;
	int		width;
	int		height;
	int		won;
	int		lost;
}				t_window;

typedef struct s_image
{
	void	*image;
	void	*address;
	int		width;
	int		height;
}				t_image;

typedef struct s_coin
{
	void	*coin1;
	void	*coin2;
	void	*address;
}				t_coin;

typedef struct s_player
{
	void	*angel1;
	void	*angel2;
	void	*angel3;
	void	*angel4;
	void	*angel5;
	void	*angel6;
	void	*angel7;
	void	*angel8;
	void	*address;
}				t_player;

typedef struct s_enemy
{
	void	*ghoul1;
	void	*ghoul2;
	void	*ghoul3;
	void	*ghoul4;
	void	*ghoul5;
	void	*ghoul6;
	void	*ghoul7;
	void	*ghoul8;
	void	*address;
}				t_enemy;

typedef struct s_sprites
{
	int			tile_size;
	t_image		background;
	t_image		wall;
	t_image		loot;
	t_image		exit;
	t_player	player;
	t_enemy		enemy;
	t_image		moves;
	t_image		collected;
	t_image		won;
	t_image		lost;
}				t_sprites;

typedef struct s_engine
{
	void		*mlx;
	t_window	window;
	t_image		image;
	t_sprites	sprites;
	t_game		game;
	t_map		map;
}				t_engine;

void	so_long_parse(char *file, t_engine *engine);

void	so_long_validate(t_engine *engine);

void	so_long_initialize(t_engine *engine);

void	so_long_init_player(t_engine *engine);
void	so_long_init_enemy(t_engine *engine);

int		so_long_main_loop(t_engine *engine);

void	so_long_draw(t_engine *engine);

void	so_long_move_up(t_engine *engine);
void	so_long_move_down(t_engine *engine);
void	so_long_move_left(t_engine *engine);
void	so_long_move_right(t_engine *engine);

t_coord	*so_long_new_coord(char letter, int x, int y);
void	so_long_add_coord(t_coord **head, t_coord *new);
void	so_long_free_coords(t_coord *coords);

void	so_long_error(char *message, t_engine *engine);

void	so_long_free(t_engine *engine);

#endif
