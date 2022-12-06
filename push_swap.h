/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 09:24:46 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/06 16:53:47 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct data
{
	int	*data;
	int	size;
}t_data;

int		valid_input(int nb_in, char **input);
int		valid_sign(char *str);
int		is_double_intab(t_data *tab);
int		is_sorted(t_data *tab);

int		build_a(int argc, char **argv, t_data *a);
char	*build_str_nb(int argc, char **argv);
void	free_tab(char ***str);

void	swap(t_data *a, char nametab);

#endif
