/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:56:50 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/22 19:57:09 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

static int	ft_nbr(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n == 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*ft_other_itoa(long int k, int size)
{
	char	*chain;

	chain = (char *)malloc(size + 1 * sizeof(char));
	if (!chain)
		return (NULL);
	chain[size--] = '\0';
	if (k < 0)
	{
		k *= -1;
		chain[0] = '-';
		while (size > 0)
		{
			chain[size--] = k % 10 + '0';
			k = k / 10;
		}
	}
	else
	{
		while (size >= 0)
		{
			chain[size--] = k % 10 + '0';
			k = k / 10;
		}
	}
	return (chain);
}

char	*ft_itoa(int n)
{
	char		*chain;
	int			size;
	long int	k;

	k = n;
	size = ft_nbr(k);
	chain = ft_other_itoa(k, size);
	return (chain);
}
