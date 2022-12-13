/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:34:10 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/13 17:09:11 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_error(char ***numbers, t_data *a, t_data *b)
{
	free_tab(numbers);
	free(a->data);
	free(b->data);
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_atoi_pushswap(const char *nptr, char ***numbers, t_data *a, t_data *b)
{
	long	i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (!ft_isdigit(nptr[i + 1]))
			ft_atoi_error(numbers, a, b);
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += (nptr[i++] - '0');
		if ((res > 2147483647 && neg == 1) || (res > 2147483648 && neg == -1))
			ft_atoi_error(numbers, a, b);
	}
	return (res * neg);
}
