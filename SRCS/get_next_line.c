#include "../INC/fdf.h"

#define BUFFER_SIZE 101

char	*read_next_line(int fd, char *saving)
{
	char	buffer[BUFFER_SIZE];
	int		read_size;

	while (ft_strchr(saving, '\n') == NULL)
	{
		read_size = read(fd, buffer, BUFFER_SIZE - 1);
		if (read_size == 0)
			return (saving);
		if (read_size < 0)
		{
			free(saving);
			return (NULL);
		}
		buffer[read_size] = 0;
		saving = ft_strjoin(saving, buffer);
	}
	return (saving);
}

char	*get_next_line(int fd)
{
	static char		*saving;
	char			*temp;
	char			*line;

	if (fd < 0)
		return (NULL);
	saving = read_next_line(fd, saving);
	if (!saving)
		return (NULL);
	temp = ft_strchr(saving, '\n');
	if (temp == NULL)
	{
		if (saving == NULL || ft_strlen(saving) == 0)
			line = NULL;
		else
			line = ft_strndup(saving, ft_strlen(saving));
		free(saving);
		saving = NULL;
		return (line);
	}
	line = ft_substr(saving, 0, temp - saving);
	temp = ft_substr(saving, temp - saving + 1, ft_strlen(temp) - 1);
	free(saving);
	saving = temp;
	return (line);
}

int	put_data_to_queue(t_queue *queue, char *arg)
{
	int			res;
	int			data;
	int			words;
	char		**info;
	t_z_n_color	z_n_color;

	words = count_words(arg, ',');
	info = ft_split(arg, ',', words);
	if (!info)
		return (FALSE);
	if (ft_atoi_base(info[0], 10, &data))
		z_n_color[0] = data;
	if (words == 1)
		z_n_color[1] = -1;
	else
	{
		res = FALSE;
		if (info[1][0] == '0' && (info[1][1] == 'x' || info[1][1] == 'X'))
			res = ft_atoi_base(info[1] + 2, 16, z_n_color + 1);
	}
	delete_splited_charset(info, words);
	ft_enqueue(queue, z_n_color);
	if (res == FALSE)
		return (FALSE);
	return (TRUE);
}

int	parse_line(t_queue *queue, char *line, int *height)
{
	int		res;
	int		i;
	char	**argset;

	if (!queue || !line)
		return (FALSE);
	if (*height == 0 || *height == count_words(line, ' '))
		*height = count_words(line, ' ');
	else
		return (FALSE);
	argset = ft_split(line, ' ', *height);
	res = FALSE;
	if (argset == NULL)
		return (res);
	i = 0;
	while (argset[i])
	{
		res = put_data_to_queue(queue, argset[i]);
		if (res == FALSE)
			break ;
		i++;
	}
	delete_splited_charset(argset, *height);
	return (res);
}

/*
int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	(void)argc;
	fd = open((argv[1]), O_RDONLY);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line)
			printf("%s\n", line);
		else
			break;
		free(line);
	}
	free(line);
	return(0);
}*/