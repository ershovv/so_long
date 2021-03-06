/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:35:52 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/18 14:40:15 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 48) && (c <= 57)) || ((c >= 65) && (c <= 90))
		|| ((c >= 97) && (c <= 122)))
		return (1);
	else
		return (0);
}
