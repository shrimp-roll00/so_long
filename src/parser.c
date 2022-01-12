#include "so_long.h"

static void	check_extension(char *file, t_engine *engine)
{
	char	*dot;

	dot = ft_strrchr(file, '.');
	if (!dot || ft_strchr(file, '.') != dot
		|| ft_strncmp(dot, ".ber", ft_strlen(dot)))
		so_long_error("the map ain't .ber", engine);
}

static void	sort_into_coords(t_map *map, char *line, int y)
{
	int		x;

	x = 0;
	while (line[x])
	{
		so_long_add_coord(&map->head, so_long_new_coord(line[x], x, y));
		x++;
	}
}

static void	read_file(int fd, t_engine *engine)
{
	int		res;
	char	*temp;

	ft_bzero(&engine->map, sizeof(t_map));
	while (1)
	{
		res = get_next_line(fd, &temp);
		if (res < 0)
			so_long_error("the file ain't readable", engine);
		if (engine->map.height == 0)
			engine->map.width = (int)ft_strlen(temp);
		else if (engine->map.width != (int)ft_strlen(temp))
		{
			free(temp);
			so_long_error("the map ain't rectangular", engine);
		}
		sort_into_coords(&engine->map, temp, engine->map.height);
		engine->map.height++;
		free(temp);
		if (!res)
			break ;
	}
}

void	so_long_parse(char *file, t_engine *engine)
{
	int		fd;

	check_extension(file, engine);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		so_long_error("the file ain't readable", engine);
	read_file(fd, engine);
	so_long_validate(engine);
}
