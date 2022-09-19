/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:15:29 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/08/29 15:38:26 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	while (*s)
	{
		if ((char)*s == c)
			return (1);
		s++;
	}
	if (*s == c)
		return (1);
	return (0);
}

int	ft_strlen_trim(char *s1, char *set)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(s1);
	while (ft_strchr(set, s1[i]))
	{
		i++;
		size--;
	}
	if (size <= 0)
		return (0);
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]))
	{
		i--;
		size--;
	}
	return (size);
}

char	*ft_strdup_trim(char *s1, char *set)
{
	char	*trim;
	int		i;
	int		j;
	int		k;

	trim = malloc(ft_strlen_trim(s1, set) + 1);
	if (!trim)
		return (NULL);
	k = 0;
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[j]))
		j--;
	if (i <= j)
	{
		while (i <= j)
			trim[k++] = s1[i++];
		trim[k] = CHR_END;
		return (trim);
	}
	trim[k] = CHR_END;
	return (trim);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*trim;

	if (!s1 || (s1 && !s1[0]))
		return (NULL);
	if (!set)
		return ((char *)s1);
	trim = ft_strdup_trim(s1, set);
	return (free(s1), trim);
}
