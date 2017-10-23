/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:01:36 by ttridon           #+#    #+#             */
/*   Updated: 2015/12/22 18:17:10 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_list	*ft_lstnew(void)
{
	t_list	*lst_new;
	int		i;

	i = 0;
	lst_new = (t_list *)malloc(sizeof(t_list));
	if (!lst_new)
		return (NULL);
	while (i < 6)
	{
		lst_new->pos[i] = 5;
		i++;
	}
	lst_new->next = NULL;
	return (lst_new);
}
