#include "args.h"

void initiate_args_index(t_arglst *arglst)
{
    int             size;
    int             i;
    t_arglst_node   *curr;
    t_arg_with_idx  *arr;
    
    size = arglst->lst_size;
    if (size <= 0)
        return ;
    arr = malloc(sizeof(t_arg_with_idx) * size);
    if (!arr)
        return ;
    i = 0;
    curr = arglst->head->next;
    while (i < size)
    {
        arr[i++]->data = curr->data;
        curr = curr->next;
    }
}