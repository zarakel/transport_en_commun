


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:25:18 by tnicoue           #+#    #+#             */
/*   Updated: 2022/01/25 18:26:20 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void get_bigger_b(t_stack *)
{
    int i;

    i = 0
    while (stack_b)
    {
        if(bigger < stack_b->content)
            bigger = stack_b->content;
        stack_b = stack_b->next;
    }
    while (t_stack * t_stack_b)
    {
        if(bigger == t_stack_b->content)
            pos_bigger == i;
        i++;
        t_stack_b = t_stack_b->next;       
    }
    size_b = i;
}

void get_shorter_a(t_stack *)
{
    t_stack *tmp;
    int i;

    tmp = t_stack;
    while (tmp)
    {
        if(shorter > tmp->content && (i >= 0 && i <= 10)
            shorter = tmp->content;
        if(shorter2 > tmp->content && (i >= (size_a - 10) && i <= size_a)
            shorter2 = tmp->content;
        tmp = tmp->next;
    }
    i = 1;
    while (t_stack * t_stack_a)
    {
        if(shorter == t_stack_a->content)
            pos_shorter == i;
        if(shorter2 == t_stack_a->content)
            pos_shorter2 == i;
        i++;
        t_stack_a = t_stack_a->next;       
    }
}


int get_value(int i, t_stack *stack, int *value)
{
    int w;
    
    w = 0;
    while(w < i)
        t_stack = t_stack->next;
    value[i] = t_stack->content;
}
*/
void    direction(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
    stock->size_before =get_size(stack_a, stock);
    if (stock->size_all <= 3)
        choose_sort_short(stack_a, stock);
    else
        choose_sort_big(stack_a, stack_b, stock);
}
    
int get_size(t_stack **stack, t_stock *stock)
{
    t_stack *tmp;
    int     i;
    
    tmp = (*stack);
    i = 0;
    while(tmp)
    {
        i++;
        tmp = tmp->next;
    }
    stock->size_all = i;
    return (i);
}

void choose_sort_short(t_stack **stack_a, t_stock *stack)
{
    if(stack->size_all == 2)
        ft_tri2(stack_a);
    else if(stack->size_all == 3)
        ft_tri3(stack_a);
}

void ft_tri2(t_stack **stack_a)
{
    if((*stack_a)->content > (*stack_a)->next->content)
        ft_sa(stack_a);
}

void ft_tri3(t_stack **stack_a)
{
    if((*stack_a)->content < (*stack_a)->next->content 
        && (*stack_a)->content < (*stack_a)->next->next->content
        && (*stack_a)->next->content > (*stack_a)->next->next->content) //132
    {
        ft_sa(stack_a);
        ft_ra(stack_a);
    }
    else if((*stack_a)->content < (*stack_a)->next->content 
        && (*stack_a)->content > (*stack_a)->next->next->content) //231
        ft_rra(stack_a);
    else if ((*stack_a)->content > (*stack_a)->next->content 
        && (*stack_a)->content > (*stack_a)->next->next->content
        && (*stack_a)->next->content < (*stack_a)->next->next->content) //312
        ft_ra(stack_a);
    else if ((*stack_a)->content > (*stack_a)->next->content 
        && (*stack_a)->next->content < (*stack_a)->next->next->content) //213
        ft_sa(stack_a);
    else if((*stack_a)->content > (*stack_a)->next->content 
        && (*stack_a)->content > (*stack_a)->next->next->content
        && (*stack_a)->next->content > (*stack_a)->next->next->content) //321
    {
        ft_sa(stack_a);
        ft_rra(stack_a);
    }
    else if ((*stack_a)->content < (*stack_a)->next->content
        && (*stack_a)->content < (*stack_a)->next->next->content
        && (*stack_a)->next->content < (*stack_a)->next->next->content)
        return ;                                                        //123
}

void choose_sort_big(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
	get_size(stack_a, stock);
    if(stock->size_all == 4)
        ft_tri4(stack_a, stack_b, stock);
    else if(stock->size_all == 5)
        ft_tri5(stack_a, stack_b, stock);
    else if(stock->size_all <= 100)
	{
        set_nb_chunk(stock);
        ft_tri100(stack_a, stack_b, stock);
	}
    /*else if (stock->size_all > 100 && stock->size_all <= 500)
        ft_big_sort500(stack_a, stack_b, stock);
		set_nb_chunk(stack_a);*/
}

void	set_nb_chunk(t_stock *stock)
{	
	if (stock->size_all <= 100)
		stock->nchunk = 5;
	else if (stock->size_all >= 100 && stock->size_all <= 500)
		stock->nchunk = 12;
	else
		stock->nchunk = stock->size_all / 15;
	stock->limit = stock->size_all / stock->nchunk;
}

void getlower4_5(t_stack **stack_a, t_stock *stock)
{
    t_stack *tmp;
    int i;

    i = 0;
    tmp = (*stack_a);
    while (tmp)
    {
        if(stock->shorter > tmp->content)
        {
           stock->shorter = tmp->content;
           stock->pos_shorter = i;
        }
        tmp = tmp->next;
        i++;
    }
}

void mvlower4(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
    int i;

    i = stock->pos_shorter;
    if (i == 3)
    {
        ft_rra(stack_a);
        ft_pb(stack_a, stack_b, stock);
    }
    else
    {
        while (i != 0)
        {
            ft_ra(stack_a);
            i--;
        }
        ft_pb(stack_a, stack_b, stock);
    }
}
 
void    ft_tri4(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
    getlower4_5(stack_a, stock);
    mvlower4(stack_a, stack_b, stock);
    ft_tri3(stack_a);
    ft_pa(stack_a, stack_b, stock);
}

void    ft_tri5(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
    getbigger5(stack_a, stock);
    mvbigger5(stack_a, stack_b, stock);
    getlower4_5(stack_a, stock);
    mvlower4(stack_a, stack_b, stock);
    ft_tri3(stack_a);
    ft_pa(stack_a, stack_b, stock);
    ft_pa(stack_a, stack_b, stock);
    ft_ra(stack_a);
}

void    mvbigger5(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
    int count;

    count = 5 - stock->pos_bigger;
    if (stock->pos_bigger > 2)
    {
        while(count > 0)
        {
            ft_rra(stack_a);
            count--;
        }
        ft_pb(stack_a, stack_b, stock);
    }
    else
    {
        while (stock->pos_bigger)
        {
            ft_ra(stack_a);
            stock->pos_bigger--;
        }
        ft_pb(stack_a, stack_b, stock);
    }
}

void    getbigger5(t_stack **stack_a, t_stock *stock)
{
    int i;

    i = 0;
    t_stack *tmp;
    tmp = (*stack_a);
    while (tmp)
    {
        if(stock->bigger < tmp->content)
        {
            stock->bigger = tmp->content;
            stock->pos_bigger = i;
        }
        tmp = tmp->next;
        i++;
    }
}

void get_size_a(t_stack **stack_a, t_stock *stock)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = (*stack_a);
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    stock->size_a = i;
}

void get_size_b(t_stack **stack_b, t_stock *stock)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = (*stack_b);
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    stock->size_b = i;
}

void    ft_tri100(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{   
    int	nb_chunk;

	get_size(stack_a, stock);
	nb_chunk = 1;
	ft_cout(stack_a, stack_b, stock);
	/*get_size_b(stack_b, stock);
	while (stock->size_b)
		ft_pa(stack_a, stack_b, stock);*/
}	

void	ft_cout(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
	int chunk;
	int save;
	int i;

	i = 0;
	chunk = stock->size_all / stock->nchunk;
	save = chunk;
	while(i != chunk && chunk < stock->size_all)
	{   
        stock->pos_shorter = ft_recherche(*stack_a, chunk, stock);
		ft_remonte(stack_a, stack_b, stock);
        printf("----- stack_a ----\n");
        ft_print_lst(*stack_a);
        printf("----- stack_b ----\n");
        ft_print_lst(*stack_b);
		i++;
		if (i == chunk)
			chunk += save;
        printf("i = %d\n", i);
        printf("chunk = %d\n", chunk);
	}
}

int		ft_recherche(t_stack *stack_a, int chunk, t_stock *stock)
{
	int up;
	int down;
    int val;

    t_stack *tmp;
    t_stack *tmp2;
    t_stack *tmp3;

	up = 0;
	down = 0;
	tmp = stack_a;
	tmp2 = stack_a;
    tmp3 = stack_a;
	
	while(tmp->content > chunk)
	{
		tmp = tmp->next;
		up++;
	}
    printf("tmp->content = %d && up = %d\n", tmp->content, up);
	while(tmp2)
    {
        if(tmp2->content <= chunk)
            val = tmp2->content;
        tmp2 = tmp2->next;
	}
    while(tmp3->content != val)
    {
        tmp3 = tmp3->next;
        down++;
    }
    printf("up = %d\n", up);
    printf("down = %d\n", stock->size_all - down);
	if (up < stock->size_all - down)
		return (up);
	else
		return(down);
}

void	ft_remonte(t_stack **stack_a, t_stack **stack_b, t_stock *stock)
{
	if (stock->pos_shorter < stock->size_a / 2)
	{
		while(stock->pos_shorter != 0)
		{
            printf("stock_pos_shorter = %d\n", stock->pos_shorter);
			ft_ra(stack_a);
			stock->pos_shorter--;
		}
		ft_pb(stack_a, stack_b, stock);
	}
	else if (stock->pos_shorter > stock->size_a / 2)
	{
		while(stock->pos_shorter != stock->size_a)
		{
			ft_rra(stack_a);
			stock->pos_shorter++;
		}
		ft_pb(stack_a, stack_b, stock);
	}
}
/*int   ft_indic100(t_stack **stack_a, t_stock *stock)
{
    int i;
    int val;
    t_stack *tmp;

    i = 0;
    val = INT_MAX;
    tmp = (*stack_a);
    while(tmp)
    {
        if (val > tmp->content)
            val = tmp->content;
        tmp = tmp->next;
        i++;
    }
	stock->shorter = val;
	return (val);
}

int	ft_pos(t_stack **stack_a, int val, t_stock *stock)
{
	int i;
	t_stack *tmp;

	i = 1;
	tmp = (*stack_a);
	while(tmp->content != val)
	{
		tmp = tmp->next;
		i++;
	}
	stock->pos_shorter = i;
	return (i);
}
*/
