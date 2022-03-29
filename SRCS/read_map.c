/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:48:09 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/30 01:59:35 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"
#include <fcntl.h>

t_map_org	*init_map(int width, int height)
{
	int			i;
	t_map_org	*map;

	map = malloc(sizeof(t_map_org));
	if (!map)
		return (NULL);
	map->width = width;
	map->arr = malloc(sizeof(t_z_n_color *) * height);
	if (!map->arr)
	{
		free(map);
		return (NULL);
	}
	i = -1;
	while (++i < height)
	{
		map->arr[i] = malloc(sizeof(t_z_n_color) * width);
		map->height = i + 1;
		if (!map->arr[i])
		{
			delete_map_org(map);
			return (NULL);
		}
	}
	return (map);
}

void	delete_map_org(t_map_org *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->arr[i]);
	free(map->arr);
	free(map);
}

t_queue	*get_point_queue(int fd, int *width, int *height)
{
	int		i;
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
		if (!parse_line(point_queue, line, height))
		{
			ft_delete_queue(point_queue);
			point_queue = NULL;
			break ;
		}
		*width += 1;
	}
	return (point_queue);
}

void	set_origin_map(t_map_org *map, t_queue *queue)
{
	int		i;
	int		j;
	t_qnode	*node;

	i = -1;
	while (++i < map->width)
	{
		j = -1;
		while (++j < map->height)
		{
			node = ft_dequeue(queue);
			map->arr[j][i][0] = node->data[0];
			map->arr[j][i][1] = node->data[1];
			free(node);
		}
	}
}

t_map_org	*get_origin_map(char *filepath)
{
	int			width;
	int			height;
	int			fd;
	t_queue		*point_queue;
	t_map_org	*origin_map;

	width = 0;
	height = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	point_queue = get_point_queue(fd, &width, &height);
	if (!point_queue)
	{
		close(fd);
		return (NULL);
	}
	origin_map = init_map(width, height);
	if (origin_map != NULL)
		set_origin_map(origin_map, point_queue);
	ft_delete_queue(point_queue);
	close(fd);
	return (origin_map);
}


void	print_orgmap(t_map_org *org)
{
	int	i;
	int	j;
	int	r;
	int	g;
	int	b;

	i = -1;
	while (++i < org->height)
	{
		j = -1;
		while (++j < org->width)
		{
			// r = (org->arr[i][j][1] & 0XFF0000) >> 16;
			// g = (org->arr[i][j][1] & 0X00FF00) >> 8;
			// b = (org->arr[i][j][1] & 0X0000FF);
			r = 0xff - org->arr[i][j][0] * 10;
			b = 0xff - org->arr[i][j][0] * 10;
			g = 0xff;
			printf("\033[38;2;%d;%d;%dm [% 3d]\033[0m", r, g, b, org->arr[i][j][0]);
		}
		printf("\n\n");
	}
}

int 	main(int argc, char ** argv)
{
	t_map_org *map = get_origin_map(argv[argc - 1]);
	if (map == NULL)
		printf("ERROR");
	else
		print_orgmap(map);
}