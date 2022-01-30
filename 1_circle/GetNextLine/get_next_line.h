/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:29:31 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/10 20:33:12 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include<unistd.h>
# include<stdlib.h>
# include<limits.h>
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

int		gnl_strlen(char *str);
char	*gnl_strcalloc(int len);
char	*gnl_strrealloc(char *str, int size);
char	*gnl_strchr(char *str, char c);
char	*gnl_substr(char const *str, unsigned int start, size_t size);
char	*gnl_strappend(char *front, char *end);
int		gnl_cutstr(char *org, char **front, char **rear, char c);
char	*get_next_line(int fd);
#endif
