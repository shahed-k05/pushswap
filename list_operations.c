/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:18:46 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 09:18:48 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = value;
	new -> indx = -1;
	new -> next = NULL;
	return (new);
}

void	ft_lstadd_back(t_stack **ls, t_stack *new)
{
	t_stack	*h;

	if (!ls || !new)
		return ;
	if (!*ls)
	{
		*ls = new;
		return ;
	}
	h = ft_lstlast(*ls);
	h -> next = new;
}

t_stack	*ft_lstlast(t_stack *ls)
{
	t_stack	*last;

	if (!ls)
		return (NULL);
	last = ls;
	while (last)
	{
		if (last -> next == NULL)
			return (last);
		last = last -> next;
	}
	return (NULL);
}

int	ft_lstsize(t_stack *ls)
{
	int	size;

	size = 0;
	while (ls)
	{
		size++;
		ls = ls->next;
	}
	return (size);
}
