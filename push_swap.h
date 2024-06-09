/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:43:30 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/06/09 16:43:44 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "fcntl.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				position;
	int				push_price;
	int				above_median;
	int				cheapest;
	struct s_stack	*next;
	struct s_stack	*target;
}				t_stack;

//***** AUXILIAR FUNTIONS FOR CHECKING WHILE WORK IN PROGRESS*****//
ssize_t	my_write(int fd, const void *buf, size_t count);

//************ CONTROL FUNTIONS *************************************//
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *s);
int		ft_counterwords(char const *s, char c);
char	**ft_splitwords(char **split, char const *s, char c);
int		ft_atoi(char *str, t_stack *a);
int		is_correct(char **argv, t_stack **a);
void	is_not_repeated(int numb, t_stack **a);
void	process_arguments(char **arv, t_stack **a);

//*********** LISTS FUNTIONS ***************************//

void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int *content);
void	ft_free_split(char **split);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t num_elements, size_t element_size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *str);
char	*funtion_read( char *line, int fd);
char	*ft_nextline(char *line);
void	process_checker(t_stack **a, t_stack **b);
void	checker(t_stack **a, t_stack **b, char *line);
int		ft_strcmp(char *s1, char *s2);
void	error_check(t_stack **a, t_stack **b);
//************** MOVEMENTS *****************************//
void	rotate(t_stack **stack);
void	ra(t_stack **a, int check);
void	rb(t_stack **b, int check);
void	rr(t_stack **a, t_stack **b, int check);
void	swap(t_stack **stack);
void	sa(t_stack **a, int check);
void	sb(t_stack **b, int check);
void	ss(t_stack **a, t_stack **b, int check);
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a, int check);
void	rrb(t_stack **b, int check);
void	rrr(t_stack **a, t_stack **b, int check);
void	push(t_stack **orig, t_stack **dest);
void	pa(t_stack **b, t_stack **a, int check);
void	pb(t_stack **a, t_stack **b, int check);

//************** SETTINGS FOR THE LIST ******************//
void	push_swap(t_stack **a, t_stack **b);
void	first_check(t_stack **current);
t_stack	*find_higgest(t_stack *stack);
t_stack	*find_smaller(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);
void	get_target(t_stack *a, t_stack *b);
void	get_position(t_stack *stack);
void	initialize(t_stack **a, t_stack **b);
void	moves(t_stack **a, t_stack **b);
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	get_cheapest(t_stack *b);
void	get_price(t_stack *a, t_stack *b);
int		is_sorted(t_stack **a);
void	error(t_stack *a);
void	*ft_memset(void *b, int c, size_t len);
void	get_index(t_stack **a);
void	first_moves(t_stack **a, t_stack **b);

#endif