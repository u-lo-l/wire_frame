/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:48:09 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/02 22:32:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC_B/fdf_bonus.h"
#include <fcntl.h>

t_inputmap	*init_map(int sizeof_y, int sizeof_x)
{
	int			i;
	t_inputmap	*map;

	map = malloc(sizeof(t_inputmap));
	if (!map)
		return (NULL);
	map->sizeof_y = sizeof_y;
	map->arr = malloc(sizeof(t_ivec2 *) * sizeof_x);
	if (!map->arr)
	{
		free(map);
		return (NULL);
	}
	i = -1;
	while (++i < sizeof_x)
	{
		map->arr[i] = malloc(sizeof(t_ivec2) * sizeof_y);
		map->sizeof_x = i + 1;
		if (!map->arr[i])
		{
			delete_map_org(map);
			return (NULL);
		}
	}
	return (map);
}

void	delete_map_org(t_inputmap *map)
{
	int	i;

	i = 0;
	while (i < map->sizeof_x)
		free(map->arr[i++]);
	free(map->arr);
	free(map);
}

t_queue	*get_point_queue(int fd, int *sizeof_y, int *sizeof_x)
{
	char	*line;
	t_queue	*point_queue;

	point_queue = ft_create_queque();
	if (!point_queue)
		return (NULL);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (!parse_line(point_queue, line, sizeof_y))
		{
			ft_delete_queue(point_queue);
			point_queue = NULL;
			break ;
		}
		free(line);
		*sizeof_x += 1;
	}
	free(line);
	return (point_queue);
}

void	set_origin_map(t_inputmap *map, t_queue *queue)
{
	int		x;
	int		y;
	t_qnode	*node;

	set_ivector2(-2147483648, 2147483647, map->altitude);
	x = -1;
	while (++x < map->sizeof_x)
	{
		y = -1;
		while (++y < map->sizeof_y)
		{
			node = ft_dequeue(queue);
			map->arr[x][y][0] = node->data[0];
			map->arr[x][y][1] = node->data[1];
			if (node->data[0] > map->altitude[0])
				map->altitude[0] = node->data[0];
			if (node->data[0] < map->altitude[1])
				map->altitude[1] = node->data[0];
			free(node);
		}
	}
}

t_inputmap	*get_origin_map(char *filepath)
{
	int			sizeof_y;
	int			sizeof_x;
	int			fd;
	t_queue		*point_queue;
	t_inputmap	*origin_map;

	sizeof_y = 0;
	sizeof_x = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	point_queue = get_point_queue(fd, &sizeof_y, &sizeof_x);
	if (!point_queue)
	{
		close(fd);
		return (NULL);
	}
	origin_map = init_map(sizeof_y, sizeof_x);
	if (origin_map != NULL)
		set_origin_map(origin_map, point_queue);
	ft_delete_queue(point_queue);
	close(fd);
	return (origin_map);
}
/*
int 	main(int argc, char ** argv)
{
	t_inputmap *map = get_origin_map(argv[argc - 1]);
	if (map == NULL)
		printf("ERROR\n");
	else
		print_orgmap(map);
	delete_map_org(map);
}
*/