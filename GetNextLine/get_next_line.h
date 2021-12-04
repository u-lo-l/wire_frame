/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:29:31 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/04 18:34:16 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include<unistd.h>
# include<stdlib.h>
int		gnl_strlen(char *str);
char	*gnl_strcalloc(int len);
char	*gnl_strreallo(char *str, int size);
char	*gnl_strchr(char *str, char c);
char	*gnl_substr(char *str, int start, int size);
char	*gnl_strappend(char *front, char *end);
char	*get_next_line(int fd);
#endif
