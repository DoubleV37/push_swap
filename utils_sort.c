/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:06:04 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/14 18:32:38 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_data *a)
{
	if (a->end <= 200)
		return ((a->end / 4));
	else
		return ((a->end / 10));
}

int	get_index_max_intab(t_data *a)
{
	int	i;
	int	index_max;

	i = 0;
	index_max = 0;
	while (i < a->end)
	{
		if (a->data[index_max] < a->data[i])
			index_max = i;
		i++;
	}
	return (index_max);
}

int	get_index_min_intab(t_data *a)
{
	int	i;
	int	index_min;

	i = 0;
	index_min = 0;
	while (i < a->end)
	{
		if (a->data[index_min] > a->data[i])
			index_min = i;
		i++;
	}
	return (index_min);
}

int	get_index_max_prev_intab(t_data *a)
{
	int	i;
	int	index_max;
	int prev;

	i = 0;
	index_max = 0;
	prev = 0;
	while (i < a->end)
	{
		if (a->data[index_max] < a->data[i])
		{
			prev = index_max;
			index_max = i;
		}
		i++;
	}
	return (prev);
}

void	norm_tab(t_data *a)
{
	int	nb;
	int	max;
	int	i;
	int	*tabnorm;

	nb = a->end;
	i = 0;
	tabnorm = malloc(sizeof(int) * a->size);
	while (i < a->size)
	{
		tabnorm[i] = 1;
		i++;
	}
	while (nb > 1)
	{
		max = get_index_max_intab(a);
		tabnorm[max] = nb;
		a->data[max] = -2147483648;
		nb--;
	}
	free(a->data);
	a->data = tabnorm;
}
