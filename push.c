/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:17:04 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 09:17:07 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b, t_counters *counters)
{
	t_stack	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	counters->pb++;
	counters->total_ops++;
	write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b, t_counters *counters)
{
	t_stack	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	counters->pa++;
	counters->total_ops++;
	write(1, "pa\n", 3);
}
