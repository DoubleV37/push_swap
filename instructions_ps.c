/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:10:06 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/13 14:12:27 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_instrtab(char *instr, char ***instrtab)
{
	int		i;
	char	**new_instrtab;

	i = 0;
	while ((*instrtab)[i])
		i++;
	new_instrtab = ft_calloc(sizeof(char *), (i + 2));
	i = 0;
	while ((*instrtab)[i])
	{
		new_instrtab[i] = (*instrtab)[i];
		i++;
	}
	new_instrtab[i] = instr;
	i++;
	new_instrtab[i] = NULL;
	free(*instrtab);
	(*instrtab) = new_instrtab;
}

static int	len_instr(char ***instrtab)
{
	int	i;

	i = 0;
	while ((*instrtab)[i])
		i++;
	return (i);
}

int	print_dbl_action(char ***instrtab, int i)
{
	if (len_instr(instrtab) - 1 > i
		&& (((ft_strncmp((*instrtab)[i], "sa", 2) == 0
				&& ft_strncmp((*instrtab)[i + 1], "sb", 2) == 0))
		|| (ft_strncmp((*instrtab)[i], "sb", 2) == 0
		&& ft_strncmp((*instrtab)[i + 1], "sa", 2) == 0)))
		return (ft_printf("ss\n"));
	else if (len_instr(instrtab) - 1 > i
		&& ((ft_strncmp((*instrtab)[i], "ra", 2) == 0
			&& ft_strncmp((*instrtab)[i + 1], "rb", 2) == 0)
		|| (ft_strncmp((*instrtab)[i], "rb", 2) == 0
		&& ft_strncmp((*instrtab)[i + 1], "ra", 2) == 0)))
		return (ft_printf("rr\n"));
	else if (len_instr(instrtab) - 1 > i
		&& ((ft_strncmp((*instrtab)[i], "rra", 3) == 0
			&& ft_strncmp((*instrtab)[i + 1], "rrb", 3) == 0)
		|| (ft_strncmp((*instrtab)[i], "rrb", 3) == 0
		&& ft_strncmp((*instrtab)[i + 1], "rra", 3) == 0)))
		return (ft_printf("rrr\n"));
	return (-1);
}

void	print_instr(char ***instrtab)
{
	int	i;

	if (!(*instrtab))
		return ;
	i = 0;
	while ((*instrtab)[i])
	{
		if (print_dbl_action(instrtab, i) > 0)
		{
			i++;
		}
		else
			ft_printf("%s\n", (*instrtab)[i]);
		i++;
	}
	free((*instrtab));
}
