/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:59:44 by ttridon           #+#    #+#             */
/*   Updated: 2015/12/29 11:03:25 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_list
{
	int				pos[6];
	int				letter;
	struct s_list	*next;
}					t_list;

typedef struct		s_pos
{
	int				i;
	int				j;
}					t_pos;

void				ft_lstaddend(t_list **lst, t_list *lst_new);
char				**ft_creat_grille(int taille);
int					ft_resolve(t_list *lst, char **grille, int k);
t_list				*ft_read_map(char **av);
t_list				*ft_tetriminos(char *buf);
t_list				*ft_lstnew(void);

#endif
