/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:06:04 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/16 10:51:57 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_data *a)
{
	if (a->end <= 200)
		return ((a->end / 4));
	else
		return ((a->end / 9));
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

int	is_intab(t_data *a, int val)
{
	int	i;

	i = 0;
	while (i < a->end)
	{
		if (val == a->data[i])
			return (1);
		i++;
	}
	return (0);
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
