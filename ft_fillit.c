/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:48:04 by hcaspar           #+#    #+#             */
/*   Updated: 2016/01/11 13:48:08 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

static void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

static void	ft_erase_grille(char **grille)
{
	int j;

	j = 0;
	while (grille[j])
	{
		free(grille[j]);
		j++;
	}
	free(grille);
}

static void	ft_puttab(char **tab)
{
	int i;
	int j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			write(1, &tab[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int			main(int ac, char **av)
{
	t_list	*lst;
	char	**grille;
	int		taille;
	int		cond;

	cond = 0;
	taille = 2;
	if (ac != 2)
		ft_error();
	lst = ft_read_map(av);
	while (cond != 1)
	{
		grille = ft_creat_grille(taille);
		if (ft_resolve(lst, grille, 0) != 1)
			ft_erase_grille(grille);
		else
			cond = 1;
		taille++;
	}
	ft_puttab(grille);
	return (0);
}
