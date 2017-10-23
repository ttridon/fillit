/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 17:21:08 by ttridon           #+#    #+#             */
/*   Updated: 2015/12/29 11:02:50 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_write_tetri(t_list *lst, char **grille, t_pos pos, int k)
{
	int taille;

	taille = ft_strlen(grille[0]);
	if (pos.j + lst->pos[1] >= taille || pos.j + lst->pos[3] >= taille
			|| pos.j + lst->pos[5] >= taille)
		return (0);
	if (pos.i + lst->pos[0] >= taille || pos.i + lst->pos[2] >= taille
			|| pos.i + lst->pos[4] >= taille)
		return (0);
	if (grille[pos.j + lst->pos[1]][pos.i + lst->pos[0]] != '.'
			|| grille[pos.j + lst->pos[3]][pos.i + lst->pos[2]] != '.'
			|| grille[pos.j + lst->pos[5]][pos.i + lst->pos[4]] != '.')
		return (0);
	else
	{
		grille[pos.j][pos.i] = 'A' + k;
		grille[pos.j + lst->pos[1]][pos.i + lst->pos[0]] = 'A' + k;
		grille[pos.j + lst->pos[3]][pos.i + lst->pos[2]] = 'A' + k;
		grille[pos.j + lst->pos[5]][pos.i + lst->pos[4]] = 'A' + k;
	}
	return (1);
}

static void	ft_delete_tetri(char **grille, int k)
{
	int i;
	int j;
	int cnt;

	i = -1;
	j = -1;
	cnt = 0;
	while (grille[++j] && cnt != 4)
	{
		i = -1;
		while (grille[j][++i] && cnt != 4)
			if (grille[j][i] == 'A' + k)
			{
				grille[j][i] = '.';
				cnt++;
			}
	}
}

int			ft_resolve(t_list *lst, char **grille, int k)
{
	t_pos pos;

	pos.j = -1;
	if (!lst)
		return (1);
	while (grille[++pos.j])
	{
		pos.i = -1;
		while (grille[pos.j][++pos.i])
		{
			if (grille[pos.j][pos.i] == '.')
				if (ft_write_tetri(lst, grille, pos, k) == 1)
				{
					if (ft_resolve(lst->next, grille, k + 1) == 0)
						ft_delete_tetri(grille, k);
					else
						return (1);
				}
		}
	}
	return (0);
}
