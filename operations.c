/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:34:10 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/11 17:47:37 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_data *a, char nametab, char ***instr)
{
	int	tmp;

	if (a->size >= 2)
	{
		tmp = a->data[0];
		a->data[0] = a->data[1];
		a->data[1] = tmp;
		if (nametab == 'a')
			add_instrtab("sa", instr);
		else
			add_instrtab("sb", instr);
	}
}

void	push(t_data *a, t_data *b, char nametab, char ***instr)
{
	if (nametab == 'a' && b->size >= 2)
	{
		addfront_data(a, b->data[0]);
		removefront_data(b);
		add_instrtab("pa", instr);
	}
	if (nametab == 'b' && a->size >= 2)
	{
		addfront_data(b, a->data[0]);
		removefront_data(a);
		add_instrtab("pb", instr);
	}
}

void	rotate(t_data *a, char nametab, char ***instr)
{
	int	val;

	val = a->data[0];
	removefront_data(a);
	addback_data(a, val);
	if (nametab == 'a')
		add_instrtab("ra", instr);
	else
		add_instrtab("rb", instr);
}

void	reverse_rotate(t_data *a, char nametab, char ***instr)
{
	int	val;

	val = a->data[a->end - 1];
	removeback_data(a);
	addfront_data(a, val);
	if (nametab == 'a')
		add_instrtab("rra", instr);
	else
		add_instrtab("rrb", instr);
}
