/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 03:48:42 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/03 16:44:17 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

char	*getval(char *s, int start, int len)
{
	size_t	s_len;
	char	*sub_tkn;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		s_len = 1;
	else if (len > ft_strlen(s))
		s_len = ft_strlen(s) + 1;
	else
		s_len = len + 1;
	sub_tkn = (char *)malloc(s_len);
	if (!(sub_tkn))
		return (NULL);
	sub_tkn[--s_len] = CHR_END;
	while (s_len-- > 0)
		sub_tkn[s_len] = s[s_len + start];
	return (sub_tkn);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	free_arr2d(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

char	*concat(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = "";
	i = 0;
	j = 0;
	new = NULL;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	new = malloc(i + j);
	if (!new)
		return (NULL);
	new[i + j] = CHR_END;
	while (--j >= 0)
		new[i + j] = s2[j];
	while (--i >= 0)
		new[i] = s1[i];
	return (new);
}
