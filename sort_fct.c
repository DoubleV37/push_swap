/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:51:09 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/16 17:19:31 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
