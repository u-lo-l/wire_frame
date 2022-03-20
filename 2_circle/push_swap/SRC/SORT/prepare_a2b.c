/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_a2b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:52:16 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/18 02:52:30 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/push_swap.h"

void	case_rr(t_mystack *A, t_mystack *B, t_actions *acts)
{
	int	i;

	i = 0;
	while (i < acts->ra && i < acts->rb)
	{
		act_rot(A, B);
		i++;
	}
	while (i < acts->ra)
	{
		act_rot(A, NULL);
		i++;
	}
	while (i < acts->rb)
	{
		act_rot(B, NULL);
		i++;
	}
}

void	case_rrr(t_mystack *A, t_mystack *B, t_actions *acts)
{
	int	i;

	i = 0;
	while (i < acts->rra && i < acts->rrb)
	{
		act_rrot(A, B);
		i++;
	}
	while (i < acts->rra)
	{
		act_rrot(A, NULL);
		i++;
	}
	while (i < acts->rrb)
	{
		act_rrot(B, NULL);
		i++;
	}
}

void	case_else(t_mystack *A, t_mystack *B, t_actions *acts)
{
	int	i;

	i = -1;
	if (acts->ra < acts->rra)
		while (++i < acts->ra)
			act_rot(A, NULL);
	else
		while (++i < acts->rra)
			act_rrot(A, NULL);
	i = -1;
	if (acts->rb < acts->rrb)
		while (++i < acts->rb)
			act_rot(B, NULL);
	else
		while (++i < acts->rrb)
			act_rrot(B, NULL);
}
