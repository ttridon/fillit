/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_grille.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:22:15 by ttridon           #+#    #+#             */
/*   Updated: 2015/12/28 16:18:02 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_fill_point(char *grille, int taille)
{
	int i;

	i = 0;
	while (i < taille)
	{
		grille[i] = '.';
		i++;
	}
	grille[i] = '\0';
}

char		**ft_creat_grille(int taille)
{
	char	**grille;
	int		i;

	i = 0;
	grille = (char **)malloc(sizeof(char *) * taille + 1);
	while (i < taille)
	{
		grille[i] = (char *)malloc(sizeof(char) * taille + 1);
		ft_fill_point(grille[i], taille);
		i++;
	}
	grille[i] = NULL;
	return (grille);
}
