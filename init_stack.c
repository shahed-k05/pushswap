/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:18:36 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 09:18:38 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **a, char **argv)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (argv[i])
	{
		new = ft_lstnew(ft_atol(argv[i]));
		ft_lstadd_back(a, new);
		i++;
	}
	index_stack(*a);
}

t_stack	*get_min(t_stack *a)
{
	t_stack	*head;
	t_stack	*min;

	min = NULL;
	head = a;
	while (head)
	{
		if ((min == NULL || min->value > head->value) && head->indx == -1)
			min = head;
		head = head->next;
	}
	return (min);
}

void	index_stack(t_stack *a)
{
	t_stack	*min;
	int		index;

	index = 0;
	while (1)
	{
		min = get_min(a);
		if (!min)
			break ;
		min->indx = index;
		index++;
	}
}
