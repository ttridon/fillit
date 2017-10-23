/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:24:48 by ttridon           #+#    #+#             */
/*   Updated: 2015/12/29 10:57:57 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

t_list		*ft_read_map(char **av)
{
	t_list	*lst;
	char	buf[22];
	int		fd;
	int		ret;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	lst = NULL;
	buf[21] = '\0';
	while ((ret = read(fd, buf, 21)))
		if (ret == 21)
			ft_lstaddend(&lst, ft_tetriminos(buf));
		else if (ret == 20 && (i = 1))
			ft_lstaddend(&lst, ft_tetriminos(buf));
		else
			ft_error();
	if (close(fd) != 0 || i != 1)
		ft_error();
	return (lst);
}
