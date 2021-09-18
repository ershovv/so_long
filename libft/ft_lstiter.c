/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:15:20 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/25 15:17:32 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	i;

	i = 0;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst -> next;
		i++;
	}
}
