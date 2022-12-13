/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:51:09 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/13 13:42:39 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly_sort(t_data *a, t_data *b, char ***instrtab)
{
	/*int	pivot;
	int	div;

	div = a->end / 10 + 15;
	div = a->end / div;
	if (div == 0)
		div = 3;
	pivot = a->end /div;
*/
	if (a && b && instrtab)
		return ;
	return ;
}

static int	get_index_max_intab(t_data *a)
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

void	sort_size3(t_data *a, char ***instrtab)
{
	norm_tab(a);
	while (!is_sorted(a))
	{
		ft_printf("%i\n", a->data[0]);
		ft_printf("%i\n", a->data[1]);
		ft_printf("%i\n", a->data[2]);
		if ((a->data[0] == 1 && a->data[1] == 3 && a->data[2] == 2) || (a->data[0] == 2 && a->data[1] == 3 && a->data[2] == 1))
			reverse_rotate(a, 'a', instrtab);
		else if ((a->data[0] == 3 && a->data[1] == 2 && a->data[2] == 1) || (a->data[0] == 2 && a->data[1] == 1 && a->data[2] == 3))
			swap(a, 'a', instrtab);
		else if (a->data[0] == 3 && a->data[1] == 1 && a->data[2] == 2)
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
