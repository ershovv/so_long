/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:07:39 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/26 16:18:58 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tm_p;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tm_p = *lst;
		while (tm_p->next)
			tm_p = tm_p->next;
		tm_p->next = new;
	}
}
