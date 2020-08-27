#include "get_next_line.h"

static int	make_line(char **line, char **save, char *null, int return_value)
{
	char	*tmp;

	if (!(*line = ft_strdup(*save)))
	{
		SAFE_FREE(*save);
		return (1);
	}
	if (return_value == 1)
	{
		if (!(tmp = ft_strdup(null + 1)))
		{
			SAFE_FREE(*save);
			return (1);
		}
		SAFE_FREE(*save);
		*save = tmp;
	}
	else
		SAFE_FREE(*save);
	return (0);
}

static int	check_line(char **line, char **save, int read_return)
{
	int		return_value;
	char	*null;

	return_value = 0;
	if (read_return < 0)
	{
		SAFE_FREE(*save);
		return (-1);
	}
	if (!*save)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	if ((null = ft_strchr(*save, '\n')) != 0)
	{
		*null = '\0';
		return_value = 1;
	}
	if (make_line(line, save, null, return_value) == 0)
		return (return_value);
	return (-1);
}

static int	make_save(char **save, char **buf)
{
	char	*tmp;

	if (!*save)
	{
		if (!(*save = ft_strdup(*buf)))
		{
			SAFE_FREE(*buf);
			return (-1);
		}
	}
	else
	{
		if (!(tmp = ft_strjoin(*save, *buf)))
		{
			SAFE_FREE(*save);
			SAFE_FREE(*buf);
			return (-1);
		}
		SAFE_FREE(*save);
		*save = tmp;
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*save[256];
	char		*buf;
	int			read_return;

	if (!line || fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	{
		SAFE_FREE(save[fd]);
		return (-1);
	}
	while ((read_return = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_return] = '\0';
		if (make_save(&save[fd], &buf) == -1)
			return (-1);
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	SAFE_FREE(buf);
	return (check_line(line, &save[fd], read_return));
}
