/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:43:06 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/10/04 18:02:26 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!dst && !src && n != 0)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

int	add_sqt(char *line, char **expand_str)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	if (!*expand_str)
		*expand_str = ft_strdup("");
	str = *expand_str;
	while (line[i] != '\'')
		i++;
	tmp = malloc(i + 1);
	ft_memcpy(tmp, line, i);
	tmp[i] = '\0';
	*expand_str = concat(str, tmp);
	return (i + 1);
}

int	add_words(char *line, char **expand_str)
{
	char	*tmp;
	char	*char_str;

	tmp = *expand_str;
	char_str = getval(line, 0, 1);
	*expand_str = concat(tmp, char_str);
	return (0);
}

int	handel_dlr(char *line, char **expand_str)
{
	int		i;
	char	*var;
	char	*tmp;

	i = 0;
	if (ft_isdigit(line[i]))
		return (1);
	if (line[i] == '?')
	{
		tmp = *expand_str;
		*expand_str = concat(*expand_str, ft_itoa(g_data.exit_status));
		return (1);
	}
	while (line[i] && !ft_strchr(STR_SPECIAL, line[i]))
		i++;
	var = ft_malloc(i + 1, add_garbage_in);
	ft_memcpy(var, line, i);
	var[i] = 0;
	tmp = get_envval(var);
	var = *expand_str;
	*expand_str = concat(*expand_str, tmp);
	return (i);
}

char	*_expander(char *line, int dq)
{
	int		i;
	char	*expand_str;

	i = -1;
	expand_str = NULL;
	while (line[++i])
	{
		if (line[i] == '\'' && dq == 0)
			i += add_sqt(&line[i + 1], &expand_str);
		else if (line[i] == '$' && !ft_strchr(STR_SPECIAL, line[i + 1]))
			i += handel_dlr(&line[i + 1], &expand_str);
		else if (line[i] != '\"')
			i += add_words(&line[i], &expand_str);
		else if (line[i] == '\"')
		{
			if (!expand_str)
				expand_str = ft_strdup("");
			if (dq == 1)
				dq = 0;
			else
				dq = 1;
		}
	}
	return (expand_str);
}
