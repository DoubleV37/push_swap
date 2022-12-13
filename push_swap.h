/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 09:24:46 by vviovi            #+#    #+#             */
/*   Updated: 2022/12/13 13:27:40 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct data
{
	int	*data;
	int	end;
	int	size;
}t_data;

int		valid_input(int nb_in, char **input);
int		valid_sign(char *str);
int		is_double_intab(t_data *tab);
int		is_sorted(t_data *tab);

int		build_a(int argc, char **argv, t_data *a, t_data *b);
char	*build_str_nb(int argc, char **argv);
void	free_tab(char ***str);

void	swap(t_data *a, char nametab, char ***instr);
void	push(t_data *a, t_data *b, char nametab, char ***instr);
void	rotate(t_data *a, char nametab, char ***instr);
void	reverse_rotate(t_data *a, char nametab, char ***instr);

void	add_instrtab(char *instr, char ***instrtab);
void	print_instr(char ***instrtab);
void	ft_atoi_error(char ***numbers, t_data *a);
int		ft_atoi_pushswap(const char *nptr, char ***numbers, t_data *a);

void	parsing(int argc, char **argv, t_data *a, t_data *b);
void	push_swap(t_data *a, t_data *b,char ***instr);

void	addfront_data(t_data *a, int nbr);
void	addback_data(t_data *a, int nbr);
void	removefront_data(t_data *a);
void	removeback_data(t_data *a);

void	butterfly_sort(t_data *a, t_data *b, char ***instrtab);
void	sort_size3(t_data *a, char ***instrtab);
void	sort_size4(t_data *a, t_data *b, char ***instrtab);
void	sort_size5(t_data *a, t_data *b, char ***instrtab);

#endif
