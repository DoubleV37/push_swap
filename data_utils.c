/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:47:32 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/11 19:47:17 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addfront_data(t_data *a, int nbr)
{
	int	i;

	a->end++;
	i = a->end - 1;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[i] = nbr;
}

void	addback_data(t_data *a, int nbr)
{
	a->end++;
	a->data[a->end - 1] = nbr;
}

void	removefront_data(t_data *a)
{
	int	i;
	int	tmp;

	a->end--;
	i = 0;
	while ((i + 1) <= a->end)
	{
		tmp = a->data[i + 1];
		a->data[i] = tmp;
		i++;
	}
}

void	removeback_data(t_data *a)
{
	a->end--;
}
