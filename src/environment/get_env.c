/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:45:32 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 15:05:20 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	ft_index_key(char *data)
{
	int	i;

	i = -1;
	while (data[++i])
	{
		if (data[i] == CHR_EQL)
			break ;
	}
	return (i);
}

char	*ft_key(char *data)
{
	int		len;
	char	*str;

	len = 0;
	len = ft_index_key(data);
	str = ft_substr_out(data, 0, len);
	if (!str)
		return (NULL);
	return (str);
}

char	*find_env(char *path)
{
	t_env	*env;

	env = g_data.g_envlst;
	if (!env)
		return (NULL);
	if (path)
	{
		while (env)
		{
			if (!ft_strcmp(path, env->var))
				return (env->val);
			env = env->next;
		}
	}
	return (NULL);
}

int	ft_not_exist(char *str, t_env *head)
{
	t_env	*tmp;

	tmp = head;
	while (tmp)
	{
		if (!ft_strcmp(tmp->var, str))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

char	*ft_itoa_out(int n)
{
	char		*itoa;
	long int	tmp;
	int			size;

	tmp = n;
	size = ft_nbrlen(tmp);
	itoa = (char *)ft_malloc(size + 1, add_garbage_out);
	itoa[size--] = '\0';
	if (n == 0)
		itoa[size] = '0';
	else
	{
		put_miness(&tmp, &itoa[0]);
		while (tmp != 0)
		{
			itoa[size--] = tmp % 10 + '0';
			tmp /= 10;
		}
	}
	return (itoa);
}
