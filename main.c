/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:08:30 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/06 16:53:33 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_data *a)
{
	if (a->size == 2)
		swap(a, 'a');
}

int	main(int argc, char **argv)
{
	t_data	a;
	int		i;

	if (argc >= 2)
	{
		if (!valid_input(argc, argv))
			ft_printf("Error\n");
		else
		{
			if (!build_a(argc, argv, &a))
			{
				ft_printf("Error\n");
				return (0);
			}
			if (is_double_intab(&a))
			{
				free(a.data);
				ft_printf("Error\n");
				return (0);
			}
			if (!is_sorted(&a))
				push_swap(&a);
			//**print pour test**//
			i = 0;
			while (a.size > i)
			{
				ft_printf("|%i|\n", a.data[i]);
				i++;
			}
			free(a.data);
			//*******************//
		}
	}
	return (0);
}
