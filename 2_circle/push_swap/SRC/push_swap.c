/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:52:45 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/18 02:53:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"

t_mystack	*init_stack_a(t_arglst *arglst)
{
	t_mystack		*stack_a;
	int				size;
	t_arglst_node	*curr;

	if (!arglst)
		return (NULL);
	size = arglst->lst_size;
	stack_a = new_stack(size);
	if (!stack_a)
	{
		delete_arglst(arglst);
		return (NULL);
	}
	stack_a->stack_name = 'a';
	curr = arglst->head->next;
	while (curr)
	{
		add_top(stack_a, curr->data);
		curr = curr->next;
	}
	delete_arglst(arglst);
	return (stack_a);
}

t_mystack	*init_stack_b(int size)
{
	t_mystack	*stack_b;

	stack_b = new_stack(size);
	if (!stack_b)
		return (NULL);
	stack_b->stack_name = 'b';
	return (stack_b);
}

void	push_swap(t_arglst *arglst)
{
	t_mystack	*stack_a;
	t_mystack	*stack_b;

	stack_a = init_stack_a(arglst);
	stack_b = init_stack_b(stack_a->max_size);
	if (!stack_a || !stack_b)
	{
		delete_stack(stack_a);
		delete_stack(stack_b);
		return ;
	}
	if (is_ascending(stack_a) != TRUE)
	{
		if (stack_a->curr == 3)
			sort_mini(stack_a);
		else
			sort_big(stack_a, stack_b);
	}
	delete_stack(stack_a);
	delete_stack(stack_b);
}

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
