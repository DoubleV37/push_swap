/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:18:22 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/13 17:07:41 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*build_str_nb(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	str = ft_strdup("\0");
	while (i < argc)
	{
		if (argv[i] == NULL)
		{
			free(str);
			return (NULL);
		}
		str = ft_strjoin_free_first_param(str, " ");
		str = ft_strjoin_free_first_param(str, argv[i]);
		i++;
	}
	if (!valid_sign(str))
	{
		free(str);
		return (NULL);
	}
	return (str);
}

void	free_tab(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
}

int	build_a(int argc, char **argv, t_data *a, t_data *b)
{
	int		i;
	char	*str;
	char	**numbers;

	i = 1;
	str = build_str_nb(argc, argv);
	if (!str)
		return (0);
	numbers = ft_split(str, ' ');
	free(str);
	i = 0;
	while (numbers[i])
		i++;
	a->data = ft_calloc(sizeof(int), i);
	a->size = i;
	a->end = i;
	b->data = ft_calloc(sizeof(int), a->size);
	b->end = 0;
	b->size = a->size;
	i = 0;
	while (numbers[i])
	{
		a->data[i] = ft_atoi_pushswap(numbers[i], &numbers, a, b);
		i++;
	}
	free_tab(&numbers);
	return (1);
}
