/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriminos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:24:30 by ttridon           #+#    #+#             */
/*   Updated: 2015/12/29 10:58:05 by ttridon          ###   ########.fr       */
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

static void	ft_valid_ligne(char *buf)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (buf[i])
	{
		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 20)
		{
			if (buf[i] != '\n')
				ft_error();
		}
		else if (buf[i] != '#' && buf[i] != '.')
			ft_error();
		else if (buf[i] == '#')
			cnt++;
		i++;
	}
	if (cnt != 4)
		ft_error();
}

static int	ft_valid_tetri(char *buf, int i)
{
	int n;

	n = 0;
	if (buf[i] == '#')
	{
		buf[i] = '*';
		n += ft_valid_tetri(buf, i + 1);
		n += ft_valid_tetri(buf, i + 5);
		if (i >= 1)
			n += ft_valid_tetri(buf, i - 1);
		if (i >= 5)
			n += ft_valid_tetri(buf, i - 5);
		n++;
	}
	return (n);
}

t_list		*ft_save_tetri(char *buf, int i)
{
	t_list	*lst;
	int		pos_x;
	int		pos_y;
	int		j;

	j = 0;
	pos_x = i % 5;
	pos_y = i / 5;
	lst = ft_lstnew();
	while (buf[++i])
		if (buf[i] == '*')
		{
			lst->pos[j] = i % 5 - pos_x;
			lst->pos[j + 1] = i / 5 - pos_y;
			j = j + 2;
		}
	return (lst);
}

t_list		*ft_tetriminos(char *buf)
{
	t_list	*lst;
	int		i;

	i = 0;
	buf[20] = '\n';
	ft_valid_ligne(buf);
	while (buf[i] != '#')
		i++;
	if (ft_valid_tetri(buf, i) != 4)
		ft_error();
	lst = ft_save_tetri(buf, i);
	return (lst);
}
