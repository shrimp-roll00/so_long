#include "libft.h"

int	big_scary_init(int fd, char **line, char **buffer, int *aread)
{
	if (fd < 0)
		return (0);
	if (!line)
		return (0);
	if (BUFFER_SIZE <= 0)
		return (0);
	*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buffer)
		return (0);
	if (read(fd, buffer, 0) < 0)
	{
		free(*buffer);
		return (0);
	}
	*aread = 1;
	return (1);
}

t_file	*get_file(t_file **files, int fd)
{
	t_file	*util;

	util = *files;
	while (util)
	{
		if (util->descriptor == fd)
			return (util);
		util = util->next;
	}
	util = malloc(sizeof(t_file));
	if (!util)
		return (0);
	util->descriptor = fd;
	util->content = ft_strdup("");
	util->next = *files;
	*files = util;
	return (util);
}

void	rearrange(t_file **files, t_file *file)
{
	t_file	*previous;
	t_file	*util;

	util = *files;
	if (util == file && !util->next)
		*files = 0;
	else if (util == file && util->next)
		*files = util->next;
	else
	{
		while (util->next != file)
			util = util->next;
		previous = util;
		previous->next = file->next;
	}
}

int	finally_over(t_file *file, t_file **files, char **line)
{
	char	*newline;
	int		len;
	char	*temp;

	newline = ft_strchr(file->content, '\n');
	if (!newline)
	{
		*line = ft_strdup(file->content);
		rearrange(files, file);
		free(file->content);
		free(file);
		if (!*line)
			return (-1);
		return (0);
	}
	len = newline - file->content;
	*line = ft_substr(file->content, 0, len);
	temp = ft_strdup(file->content + len + 1);
	free(file->content);
	if (!temp)
		return (-1);
	file->content = temp;
	if (!*line)
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static t_file	*files;
	t_file			*file;
	char			*buffer;
	int				aread;

	if (!big_scary_init(fd, line, &buffer, &aread))
		return (-1);
	file = get_file(&files, fd);
	if (!file)
		return (-1);
	while (!ft_strchr(file->content, '\n') && aread > 0)
	{
		aread = read(fd, buffer, BUFFER_SIZE);
		buffer[aread] = 0;
		file->content = ft_strjoin_free_first(file->content, buffer);
		if (!file->content)
		{
			free(buffer);
			return (-1);
		}
	}
	free(buffer);
	return (finally_over(file, &files, line));
}
