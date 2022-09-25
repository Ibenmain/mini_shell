/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:11:20 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/25 21:13:23 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	ft_index_key(char *data)
{
	int	i;

	i = -1;
	while (data[++i])
	{
		if (data[i] == '=')
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
	str = getval(data, 0, len);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_val(char *data)
{
	int		len;
	char	*str;

	len = ft_index_key(data);
	str = ft_substr(data, len + 1, ft_strlen(data) - len);
	if (!str)
		return (NULL);
	return (str);
}

t_env	*ft_creat_node(char *data)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->var = ft_key(data);
	if (!env->var)
		return (NULL);
	env->val = ft_val(data);
	if (!env->val)
		return (NULL);
	if (!ft_strcmp(env->var, "SHLVL"))
		env->val = ft_itoa(ft_atoi(env->val) + 1);
	env->next = NULL;
	return (env);
}

t_env	*init_env(char **env)
{
	int		i;
	t_env	*head;
	char	s[1024];

	i = 0;
	head = NULL;
	if (!env || !*env)
	{
		ft_lstadd_back(&head, ft_creat_node(join_add_eq("PWD", \
			getcwd(s, 1024))));
		ft_lstadd_back(&head, ft_creat_node(join_add_eq("SHLVL", "0")));
		return (head);
	}
	while (env[i])
	{
		if (ft_strcmp(*ft_split(env[i], '='), "OLDPWD"))
			ft_lstadd_back(&head, ft_creat_node(env[i]));
		i++;
	}
	return (head);
}
