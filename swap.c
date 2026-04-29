/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:17:33 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 09:17:36 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **m)
{
	t_stack	*first;
	t_stack	*second;

	if (!m || !*m || !(*m)->next)
		return ;
	first = *m;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*m = second;
}

void	sa(t_stack **a, t_counters *counters)
{
	swap(a);
	counters->sa++;
	counters->total_ops++;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b, t_counters *counters)
{
	swap(b);
	counters->sb++;
	counters->total_ops++;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, t_counters *counters)
{
	swap(a);
	swap(b);
	counters->ss++;
	counters->total_ops++;
	write(1, "ss\n", 3);
}
