/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42AbuDhabi.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:38 by rrangwan          #+#    #+#             */
/*   Updated: 2022/05/01 02:01:30 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int		len;
	int		len_a;
	int		len_b;
	int		*stack_a;
	int		*stack_b;
}	t_stacks;

void		longer_sort(t_stacks *stacks, int pivot);
void		long_sort1(t_stacks *stacks, int i, int j);
void		long_sort(t_stacks *stacks, int e);
void		move_up(int	*in_stack, int len);
void		move_down(int	*in_stack, int len);
void		long1(t_stacks *stacks);
void		short_sort(t_stacks *stacks);
void		ft_sort5(t_stacks *stacks);
void		ft_sort4(t_stacks *stacks, int x);
void		ft_sort3(t_stacks *stacks);
void		long_a(t_stacks *stacks, int i);
void		long_b(t_stacks *stacks, int i);
int			max(int *stack, int len);
void		ft_error(void);
void		ft_error2(int *stack);
int			not_sorted(int *in_stack, int len);
int			is_ints(int argc, char **argv);
int			*ft_fill(int argc, char **argv, int *in_stack);
int			no_dup(int *in_stack, int len);
void		simple_sort(int *in_stack, int len, int *temp);
void		ft_rank(int *in_stack, int len);
void		ft_parser(int argc, char **argv, int *in_stack);
void		ft_push_swap(int len, int *in_stack);
void		ft_ps(t_stacks *stacks, int len);
int			not_sorted_rev(int *in_stack, int len);
int			not_null(char **in_stack, int len);
//ops
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
//libft
long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_strlen(char *str);
//bonus
void		ft_ps_bonus(int len, int *in_stack);
int			check_str(char *str);
void		ex_ps(char *str, t_stacks *stack);
void		final_check(t_stacks *stack);
void		checker(t_stacks *stack);
void		bsa(t_stacks *stacks);
void		bsb(t_stacks *stacks);
void		bss(t_stacks *stacks);
void		bpa(t_stacks *stacks);
void		bpb(t_stacks *stacks);
void		brra(t_stacks *stacks);
void		brrb(t_stacks *stacks);
void		brrr(t_stacks *stacks);
void		bra(t_stacks *stacks);
void		brb(t_stacks *stacks);
void		brr(t_stacks *stacks);
//gnl
char		*gnl(int fd);
char		*ft_read(int fd, char *old_read);
char		*ft_line(char *old_read);
char		*ft_reread(char *old_read);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char *s, char c);
int			ft_cnt_wrds(char *s, char c);

#endif
