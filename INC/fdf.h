/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:37:26 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/29 13:01:00 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "fdf_data.h"
# include <stdio.h>

/*ft_string*/
int			ft_strlen(char *str);
char		*ft_strchr(char *str, char c);
char		*ft_substr(char *str, int start, int size);
char		*ft_strjoin(char *str1, char *str2);
char		*ft_strndup(char *str, int size);
/*util*/
void		delete_splited_charset(char **set, int size);
int			count_words(char *str, char c);
char		**ft_split(char	*str, char c, int words);
int			ft_atoi_base(char *str, int radix, int *nbr);
/*ft_queue*/
t_queue		*ft_create_queque(void);
int			ft_enqueue(t_queue *queue, t_z_n_color z_n_color);
t_qnode		*ft_dequeue(t_queue *queue);
void		ft_delete_queue(t_queue *queue);
int			is_queue_empty(t_queue *queue);

void		print_queue(t_queue *queue);
/*get_next_line*/
char		*read_next_line(int fd, char *saving);
char		*get_next_line(int fd);
int			parse_line(t_queue *queue, char *line, int *width);
int			put_data_to_queue(t_queue *queue, char *arg);

/*read MAP*/
t_map_org	*init_map(int	width, int height);
void		delete_map_org(t_map_org *map);
void		set_origin_map(t_map_org *map, t_queue *queue);
t_queue		*get_point_queue(int fd, int *width, int *height);
t_map_org	*get_origin_map(char *filename);

void		print_orgmap(t_map_org *org);

#endif