/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:49:28 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/18 02:51:34 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "circularArray/circular_array.h"
#include "args/args.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int			preprocess_res;
	t_arglst	*arglst;

	arglst = new_arglst();
	preprocess_res = preprocess_args(arglst, argc, argv);
	if (preprocess_res == ERROR)
	{
		delete_arglst(arglst);
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (preprocess_res == TRUE)
		push_swap(arglst);
	else
		delete_arglst(arglst);
	return (0);
}
