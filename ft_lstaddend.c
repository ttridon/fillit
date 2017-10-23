/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:40:53 by ttridon           #+#    #+#             */
/*   Updated: 2015/12/23 14:21:38 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_lstaddend(t_list **lst, t_list *lst_new)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp != NULL && lst_new != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = lst_new;
	}
	else if (lst_new != NULL)
		*lst = lst_new;
}
