/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:11:20 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 17:58:03 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	ft_check_env_var(t_env *head)
{
	t_env	*oldpwd;

	oldpwd = ft_malloc(sizeof(t_env), add_garbage_out);
	oldpwd->var = ft_strdup_out("OLDPWD");
	oldpwd->val = NULL;
	oldpwd->next = NULL;
	if (ft_not_exist("PWD", head))
		ft_lstadd_back(&head, ft_creat_node(join_add_eq("PWD", \
			getcwd(NULL, 0))));
	if (ft_not_exist("SHLVL", head))
		ft_lstadd_back(&head, ft_creat_node(join_add_eq("SHLVL", "0")));
	if (ft_not_exist("PATH", head))
		ft_lstadd_back(&head, ft_creat_node(join_add_eq("PATH", \
			_PATH_STDPATH)));
	ft_lstadd_back(&head, oldpwd);
}

t_env	*ft_add_oldpwd(void)
{
	t_env	*oldpwd;

	oldpwd = ft_malloc(sizeof(t_env), add_garbage_out);
	oldpwd->var = ft_strdup_out("OLDPWD");
	oldpwd->val = NULL;
	oldpwd->next = NULL;
	return (oldpwd);
}

t_env	*ft_insert_env(char **env, t_env *oldpwd, t_env *head)
{
	int		i;
	char	**split;

	i = 0;
	while (env[i])
	{
		split = ft_split(env[i], CHR_EQL);
		if (!ft_strcmp(split[0], "OLDPWD"))
			ft_lstadd_back(&head, oldpwd);
		else
			ft_lstadd_back(&head, ft_creat_node(env[i]));
		i++;
	}
	return (head);
}

t_env	*init_env(char **env)
{
	t_env	*head;
	t_env	*oldpwd;

	oldpwd = ft_add_oldpwd();
	head = NULL;
	if (!*env)
	{
		ft_lstadd_back(&head, ft_creat_node(join_add_eq("_", \
			PTH_ENV)));
		ft_check_env_var(head);
		return (head);
	}
	else
	{
		return (ft_insert_env(env, oldpwd, head));
	}
}
