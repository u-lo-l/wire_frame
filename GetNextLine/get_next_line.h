/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:29:31 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/04 20:30:33 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include<unistd.h>
# include<stdlib.h>
int		gnl_strlen(char *str);
char	*gnl_strcalloc(int len);
char	*gnl_strrealloc(char *str, int size);
char	*gnl_strchr(char *str, char c);
char	*gnl_substr(char const *str, unsigned int start, size_t size);
char	*gnl_strappend(char *front, char *end);
char	*get_next_line(int fd);
#endif
