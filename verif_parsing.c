/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:27:24 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/06 11:24:34 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input(int nb_in, char **input)
{
	int	i;
	int	j;

	i = 1;
	while (i < nb_in)
	{
		j = 0;
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]) && input[i][j] != '-'
				&& input[i][j] != '+' && input[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i] == '-' && !ft_isdigit(str[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	is_double_intab(t_data *tab)
{
	int	i;
	int	j;
	int	val_test;

	i = 0;
	while (tab->size > i)
	{
		j = i + 1;
		val_test = tab->data[i];
		while (tab->size > j)
		{
			if (val_test == tab->data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_data *tab)
{
	int	i;

	i = 1;
	while (tab->size > i)
	{
		if (tab->data[i - 1] > tab->data[i])
			return (0);
		i++;
	}
	return (1);
}
