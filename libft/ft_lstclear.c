/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:37:56 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/25 15:34:49 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tm_p;
	t_list	*tm_sl;

	while (*lst != NULL && lst != NULL)
	{
		tm_sl = *lst;
		tm_p = tm_sl->next;
		ft_lstdelone(tm_sl, del);
		*lst = tm_p;
	}
}
