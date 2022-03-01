#include "deque.h"

void	print_deque(t_deque *deque)
{
	int 			i;
	t_deque_node	*node;
	if (!deque)
		return ;
	i = 0;
	node = deque->header_node->pnext_node;
	if (is_deque_empty(deque))
	{
		printf("EMPTY\n");
		return ;
	}
	while (i < deque->curr_node_count)
	{
		printf("[%- 5d]->", node->data);
		node = node->pnext_node;
		i++;
	}
	printf("END\n");
	return ;
}

int main()
{
	t_deque *D = make_empty_deque();
	print_deque(D);
	enqueue_front(D, 1);	
	print_deque(D);
	enqueue_front(D, 10);	
	print_deque(D);
	enqueue_front(D, 12);	
	print_deque(D);
	enqueue_front(D, 3);	
	print_deque(D);
	enqueue_front(D, 5);	
	print_deque(D);
	enqueue_front(D, 6);	
	print_deque(D);
	enqueue_front(D, 8);	
	print_deque(D);
	enqueue_front(D, 13);	
	print_deque(D);
	enqueue_front(D, 1100);	
	print_deque(D);
	enqueue_front(D, -2);	
	print_deque(D);
	enqueue_front(D, 100);	
	print_deque(D);
	enqueue_front(D, -34);	
	print_deque(D);
	enqueue_front(D, 0);	
	print_deque(D);
	enqueue_front(D, 123);	
	print_deque(D);
	t_deque_node *del;
	
	del = dequeue_front(D);
	free(del);
	print_deque(D);	
	
	del = dequeue_front(D);
	free(del);
	print_deque(D);	
	
	del = dequeue_front(D);
	free(del);
	print_deque(D);	
	
	del = dequeue_front(D);
	free(del);
	print_deque(D);	
	
	del = dequeue_front(D);
	free(del);
	print_deque(D);	
	
	del = dequeue_front(D);
	free(del);
	print_deque(D);	
	
	del = dequeue_front(D);
	free(del);
	print_deque(D);	
	
	del = dequeue_front(D);
	free(del);
	print_deque(D);	
	
	del = dequeue_front(D);
	free(del);
	print_deque(D);	
	
	del = dequeue_front(D);
	free(del);
	print_deque(D);	
	
	del = dequeue_front(D);
	free(del);
	print_deque(D);	
	
	del = dequeue_front(D);
	free(del);
	print_deque(D);	

	// print_deque(D);
	// enqueue_rear(D, 1);	
	// print_deque(D);
	// enqueue_rear(D, 10);	
	// print_deque(D);
	// enqueue_rear(D, 12);	
	// print_deque(D);
	// enqueue_rear(D, 3);	
	// print_deque(D);
	// enqueue_rear(D, 5);	
	// print_deque(D);
	// enqueue_rear(D, 6);	
	// print_deque(D);
	// enqueue_rear(D, 8);	
	// print_deque(D);
	// enqueue_rear(D, 13);	
	// print_deque(D);
	// enqueue_rear(D, 1100);	
	// print_deque(D);
	// enqueue_rear(D, -2);	
	// print_deque(D);
	// enqueue_rear(D, 100);	
	// print_deque(D);
	// enqueue_rear(D, -34);	
	// print_deque(D);
	// enqueue_rear(D, 0);	
	// print_deque(D);
	// enqueue_rear(D, 123);	
	// print_deque(D);
	// t_deque_node *del;
	
	// del = dequeue_rear(D);
	// free(del);
	// print_deque(D);	
	
	// del = dequeue_rear(D);
	// free(del);
	// print_deque(D);	
	
	// del = dequeue_rear(D);
	// free(del);
	// print_deque(D);	
	
	// del = dequeue_rear(D);
	// free(del);
	// print_deque(D);	
	
	// del = dequeue_rear(D);
	// free(del);
	// print_deque(D);	
	
	// del = dequeue_rear(D);
	// free(del);
	// print_deque(D);	
	
	// del = dequeue_rear(D);
	// free(del);
	// print_deque(D);	
	
	// del = dequeue_rear(D);
	// free(del);
	// print_deque(D);	
	
	// del = dequeue_rear(D);
	// free(del);
	// print_deque(D);	
	
	// del = dequeue_rear(D);
	// free(del);
	// print_deque(D);	
	
	// del = dequeue_rear(D);
	// free(del);
	// print_deque(D);	
	
	// del = dequeue_rear(D);
	// free(del);
	// print_deque(D);
	
	delete_deque(&D);
	return 0;
}
