/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flages.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syasin <syasin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:16:06 by syasin            #+#    #+#             */
/*   Updated: 2026/02/23 11:19:53 by syasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mode	parse_flag(char *arg)
{
	if (!ft_strcmp(arg, "--simple"))
		return (SIMPLE);
	if (!ft_strcmp(arg, "--medium"))
		return (MEDIUM);
	if (!ft_strcmp(arg, "--complex"))
		return (COMPLEX);
	if (!ft_strcmp(arg, "--adaptive"))
		return (ADAPTIVE);
	return (NO_FLAG);
}
