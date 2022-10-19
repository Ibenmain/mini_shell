/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:15:29 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/10/04 16:12:41 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	ft_strlen(char *l)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((char)s[i] == c)
			return (1);
		i += 1;
	}
	if (s[i] == c)
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

	trim = ft_malloc(ft_strlen_trim(s1, set) + 1, add_garbage_in);
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
	return (trim);
}
