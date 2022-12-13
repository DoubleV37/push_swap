/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:27:24 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/13 16:53:17 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input(int nb_in, char **input)
{
	int	i;
	int	j;
	int	digit;

	i = 1;
	while (i < nb_in)
	{
		j = 0;
		digit = 0;
		if (!input[i][j])
			return (0);
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]) && input[i][j] != '-'
				&& input[i][j] != '+' && input[i][j] != ' ')
				return (0);
			if(ft_isdigit(input[i][j]))
				digit = 1;
			j++;
		}
		if (digit == 0)
			return (0);
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
		if ((str[i] == '-' && !ft_isdigit(str[i + 1]))
			|| (str[i + 1] == '-' && ft_isdigit(str[i]))
			|| (str[i + 1] == '+' && ft_isdigit(str[i])))
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
	while (tab->end > i)
	{
		if (tab->data[i - 1] > tab->data[i])
			return (0);
		i++;
	}
	return (1);
}
