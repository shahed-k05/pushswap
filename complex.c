/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:17:45 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 09:17:47 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_complex_sort(t_stack **a, t_stack **b, t_counters *counters)
{
	int	max_bits;
	int	i;
	int	size;
	int	j;

	size = ft_lstsize(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->indx >> i) & 1)
				ra(a, counters);
			else
				pb(a, b, counters);
			j++;
		}
		while (*b)
			pa(a, b, counters);
		i++;
	}
}
