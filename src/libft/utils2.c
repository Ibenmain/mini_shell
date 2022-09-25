/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 03:48:42 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/21 21:06:12 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

char	*getval(char *s, int start, int len)
{
	int		s_len;
	char	*sub_tkn;
	int		sz;

	if (!s)
		s = "";
	sz = ft_strlen(s);
	if (start >= sz)
		s_len = 1;
	else if (len > sz)
		s_len = sz;
	else
		s_len = len + 1;
	sub_tkn = malloc(s_len);
	if (!(sub_tkn))
		return (NULL);
	sub_tkn[--s_len] = CHR_END;
	while (--s_len >= 0)
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
	new = malloc(i + j + 1);
	if (!new)
		return (NULL);
	new[i + j] = CHR_END;
	while (--j >= 0)
		new[i + j] = s2[j];
	while (--i >= 0)
		new[i] = s1[i];
	return (new);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}
