/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:24:16 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/03 15:34:13 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_CHECK_H
# define ARG_CHECK_H
# include "arg_list.h"

int		count_args(char *str);

void	delete_argset(char **argset, int size);

char	**split_args(int argc, char *str);

#endif
