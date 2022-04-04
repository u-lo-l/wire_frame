/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:37:26 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/05 00:49:51 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "fdf_data.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>

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
int			ft_enqueue(t_queue *queue, t_ivec2 z_and_color);
t_qnode		*ft_dequeue(t_queue *queue);
void		ft_delete_queue(t_queue *queue);
int			is_queue_empty(t_queue *queue);

/*get_next_line*/
char		*read_next_line(int fd, char *saving);
char		*get_next_line(int fd);
int			parse_line(t_queue *queue, char *line, int *width);
int			put_data_to_queue(t_queue *queue, char *arg);

/*read MAP*/
t_inputmap	*init_map(int	width, int sizeof_x);
void		delete_map_org(t_inputmap *map);
void		set_origin_map(t_inputmap *map, t_queue *queue);
t_queue		*get_point_queue(int fd, int *width, int *sizeof_x);
t_inputmap	*get_origin_map(char *filename);

/*MATRIX*/
/*vector.c*/
int			set_ivector2(int i, int j, t_ivec2 result);
int			set_vector2(double i, double j, t_dvec2 result);
int			set_vector3(double i, double j, double k, t_dvec3 result);
int			get_unitvector(double i, double j, double k, t_dvec3 result);
int			inner_product(t_dvec3 a, t_dvec3 b, double *result);
/*vector2.c*/
int			scale_dvec(double *v1, int size, double scaler);
int			sum_dvec(double *v1, double *v2, int size);
int			diff_dvec(double *result, double *v1, double *v2, int size);
/*matrix.c*/
int			zero_33mat(t_33mat mat);
int			transpose_33matrix(t_33mat mat);
int			mat_mul(t_33mat mat1, t_33mat mat2, t_33mat result);
int			mat_dup(t_33mat mat, t_33mat dup);
/*linear transformation*/
int			tranformation_33mat(t_33mat mat, t_dvec3 u, t_dvec3 v, t_dvec3 w);
int			rotation_matrix(t_dvec3 axis, double rad, t_33mat result);
int			rotate(t_dvec3 vec, t_dvec3 axis, double rad, t_dvec3 result);
int			transform(t_dvec3 vec, t_33mat mat, t_dvec3 result);
/*view*/
int			isometric_view(t_33mat mat);

/*OUTPUT MAP*/
t_outputmap *create_ouputmap(int sizeof_y, int sizeof_x);
void		delete_outputmap(t_outputmap *output);
int			convert_map(t_inputmap *in_map, t_33mat mat, t_outputmap *out_map);
int			set_outputmap_size(t_outputmap *out);
int			set_offset_scaler_output(t_outputmap *out);

/*MiniLibX*/
/*events*/
int			mousedown(int button, int x, int y, t_mlx *mlx);
int			mouseup(int button, int x, int y, t_mlx *mlx);
int			mousemove(int x, int y, t_mlx *mlx);
int			keydown(int keycode, t_mlx *mlx);
int			destroy(t_mlx *mlx);
/*mlx*/
t_mlx		*creat_mlx(t_inputmap *in);
void		delete_mlx(t_mlx *mlx);
int			mlx_renew_image(t_mlx *mlx);
int			rotate_view(t_mlx *mlx, double rad, int dx, int dy);
int			rotate_global(t_mlx *mlx, double rad, char axis_name);
/*draw*/
void		my_mlx_pixel_put(t_image *image, int x, int y, int color);
void		my_mlx_draw_line(t_mlx *mlx, t_outputmap *out, t_ivec2 p1, t_ivec2 p2);
void		my_mlx_print_map(t_mlx *mlx);
/*color*/
void		color_to_dvec3(int color, t_dvec3 color_vec);
int			dvec3_to_color(t_dvec3 color_vec);
void	get_color_vector(t_mlx *mlx, t_ivec2 pos, t_dvec3 color_vec);

#endif