/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:18:22 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/06 16:03:38 by vviovi           ###   ########.fr       */
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

int	build_a(int argc, char **argv, t_data *a)
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
	a->data = malloc(sizeof(int) * i);
	a->size = i;
	i = 0;
	while (numbers[i])
	{
		a->data[i] = ft_atoi(numbers[i]);
		if ((a->data[i] == 0
			&& numbers[i][ft_strlen(numbers[i]) - 1] != '0')
			|| (a->data[i] == -1
			&& ft_strncmp(numbers[i], "-1", ft_strlen(numbers[i]))))
		{
			ft_printf("%i",a->data[i]);
			free_tab(&numbers);
			return (0);
		}
		i++;
	}
	free_tab(&numbers);
	return (1);
}
