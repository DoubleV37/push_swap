/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:08:30 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/13 13:58:52 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_data *a, t_data *b,char ***instr)
{
	if (a->size == 2)
		swap(a, 'a', instr);
	else if (a->size == 3)
		sort_size3(a, instr);
	else if (a->size == 4)
		sort_size4(a, b, instr);
	else if (a->size == 5)
		sort_size5(a, b, instr);
	else
		butterfly_sort(a, b, instr);
}

void	parsing(int argc, char **argv, t_data *a, t_data *b)
{
	if (!valid_input(argc, argv))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	else
	{
		if (!build_a(argc, argv, a, b))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		if (is_double_intab(a))
		{
			free(a->data);
			write(2, "Error\n", 6);
			exit(0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	a;
	t_data	b;
	char	**instr;

	if (argc >= 2)
	{
		parsing(argc, argv, &a, &b);
		if (!is_sorted(&a))
		{
			instr = malloc(sizeof(char *));
			instr[0] = NULL;
			push_swap(&a, &b, &instr);
			print_instr(&instr);
		}
		free(a.data);
		if (b.data)
			free(b.data);
	}
	return (0);
}
