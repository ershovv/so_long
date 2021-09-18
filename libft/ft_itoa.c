/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:38:49 by bshawn            #+#    #+#             */
/*   Updated: 2021/04/27 14:42:39 by bshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sym(int n)
{
	int	sym;

	if (n < 0)
		n = -n;
	sym = 0;
	while (n > 0)
	{
		n /= 10;
		sym++;
	}
	return (sym);
}

static int	checkminus(int n)
{
	int	checkminus_i;

	checkminus_i = 0;
	if (n < 0)
		checkminus_i = 1;
	return (checkminus_i);
}

static char	*record(int check, int n, int sym, char *res)
{
	int	sym_cpy;

	res = malloc(sym + check + 1);
	if (res == NULL)
		return (NULL);
	sym_cpy = sym;
	sym -= 1;
	while (n > 0)
	{
		res[sym + check] = ((n % 10) + '0');
		sym--;
		n /= 10;
	}
	if (check)
		res[0] = '-';
	res[sym_cpy + check] = '\0';
	return (res);
}

static	char	*okey_okey(void)
{
	char	*res;

	res = malloc(2);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		check;

	res = NULL;
	if (n == 0)
	{
		res = okey_okey();
		return (res);
	}
	check = checkminus(n);
	if (n == -2147483648)
	{
		res = record(check, ((n + 1) * -1), check_sym(n + 1), res);
		if (!res)
			return (NULL);
		res[10] = '8';
		return (res);
	}
	if (check)
		n = -n;
	res = record(check, n, check_sym(n), res);
	if (!res)
		return (NULL);
	return (res);
}
