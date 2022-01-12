#include "so_long.h"

t_coord	*so_long_new_coord(char letter, int x, int y)
{
	t_coord	*result;

	result = malloc(sizeof(t_coord));
	if (!result)
		return (0);
	result->letter = letter;
	result->x = x;
	result->y = y;
	result->next = 0;
	return (result);
}

void	so_long_add_coord(t_coord **head, t_coord *new)
{
	t_coord	*util;

	if (!head || !new)
		return ;
	if (!*head)
		*head = new;
	else
	{
		util = *head;
		while (util->next)
			util = util->next;
		util->next = new;
	}
}

void	so_long_free_coords(t_coord *coords)
{
	t_coord	*util;

	if (!coords)
		return ;
	while (coords->next)
	{
		util = coords;
		coords = coords->next;
		free(util);
	}
	free(coords);
}
