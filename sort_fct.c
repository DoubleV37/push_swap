/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:51:09 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/16 15:32:59 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nb_inrange(t_data *a, int min, int max)
{
	int	i;

	i = 0;
	while (a->end > i)
	{
		if (a->data[i] >= min && a->data[i] < max)
			return (1);
		i++;
	}
	return (0);
}

int	push_a_back_butterfly(t_data *a, t_data *b, char ***instrtab)
{
	if (a->data[a->end - 1] == a->size
		|| a->data[a->end - 1] < b->data[0])
	{
		push(a, b, 'a', instrtab);
		rotate(a, 'a', instrtab);
		return (1);
	}
	return (0);
}

void	push_b_butterfly(t_data *a, t_data *b, char ***instrtab)
{
	int	pivot;
	int	pivot_init;
	int min;

	norm_tab(a);
	min = 0;
	pivot_init = get_pivot(a);
	pivot = pivot_init;
	while (a->end != 0)
	{
		while (is_nb_inrange(a, min, pivot))
		{
			if (a->data[0] >= min && a->data[0] < pivot)
			{
				push(a, b, 'b', instrtab);
				if (b->data[0] < ((pivot - min) / 2) + min)
					rotate(b, 'b', instrtab);
			}
			else
				rotate(a, 'a', instrtab);
		}
		min = pivot;
		pivot += pivot_init;
	}
}

void	butterfly_sort(t_data *a, t_data *b, char ***instrtab)
{
	int max;
	int val;

	push_b_butterfly(a, b, instrtab);
	val = b->size;
	while (val > 0)
	{
		if (is_intab(b, val))
		{
			max = get_index_max_intab(b);
			while (max != 0)
			{
				if (!push_a_back_butterfly(a, b, instrtab))
				{
					if (max > (b->end / 2))
						reverse_rotate(b, 'b', instrtab);
					else
						rotate(b, 'b', instrtab);
				}
				max = get_index_max_intab(b);
			}
			push(a, b, 'a', instrtab);
		}
		else
			reverse_rotate(a, 'a', instrtab);
		val--;
	}
}

void	sort_size3(t_data *a, char ***instrtab)
{
	norm_tab(a);
	while (!is_sorted(a))
	{
		if ((a->data[0] == 1 && a->data[1] == 3
				&& a->data[2] == 2) || (a->data[0] == 2
				&& a->data[1] == 3 && a->data[2] == 1))
			reverse_rotate(a, 'a', instrtab);
		else if ((a->data[0] == 3 && a->data[1] == 2
				&& a->data[2] == 1) || (a->data[0] == 2
				&& a->data[1] == 1 && a->data[2] == 3))
			swap(a, 'a', instrtab);
		else if (a->data[0] == 3 && a->data[1] == 1
			&& a->data[2] == 2)
			rotate(a, 'a', instrtab);
	}
}

void	sort_size4(t_data *a, t_data *b, char ***instrtab)
{
	int	i;

	i = 0;
	norm_tab(a);
	while (a->data[i] != 1)
		i++;
	if (i == 1)
		swap(a, 'a', instrtab);
	else if (i == 2)
	{
		reverse_rotate(a, 'a', instrtab);
		reverse_rotate(a, 'a', instrtab);
	}
	else if (i == 3)
		reverse_rotate(a, 'a', instrtab);
	push(a, b, 'b', instrtab);
	sort_size3(a, instrtab);
	push(a, b, 'a', instrtab);
}

void	sort_size5(t_data *a, t_data *b, char ***instrtab)
{
	int	i;

	i = 0;
	norm_tab(a);
	while (a->data[i] != 1)
		i++;
	if (i == 1)
		swap(a, 'a', instrtab);
	else if (i == 2)
	{
		reverse_rotate(a, 'a', instrtab);
		reverse_rotate(a, 'a', instrtab);
		reverse_rotate(a, 'a', instrtab);
	}
	else if (i == 3)
	{
		reverse_rotate(a, 'a', instrtab);
		reverse_rotate(a, 'a', instrtab);
	}
	else if (i == 4)
		reverse_rotate(a, 'a', instrtab);
	push(a, b, 'b', instrtab);
	sort_size4(a, b, instrtab);
	push(a, b, 'a', instrtab);
}
