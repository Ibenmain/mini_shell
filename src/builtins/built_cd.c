/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:49:46 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/25 22:10:31 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	ft_print_error(char *str)
{
	printf("minishell: cd: %s not set\n", str);
}

int	ft_get_path(char *cmd)
{
	char	*path;
	char	str[1024];
	int		i;

	if (!ft_strcmp(cmd, ".") && !getcwd(str, 1024))
		perror("cd: error retrieving current directory: \
		getcwd: cannot access parent directories");
	if (!ft_strcmp(cmd, "-"))
	{
		path = find_env("OLDPWD");
		if (!path)
			return (ft_print_error("OLDPWD"), 1);
		printf("%s\n", path);
		i = chdir(path);
	}
	else if (!ft_strcmp(cmd, "~"))
	{
		path = find_env("HOME");
		if (!path)
			return (ft_print_error("HOME"), 0);
		i = chdir(path);
	}
	else
		i = chdir(cmd);
	return (i);
}

void	modife_enirement(char *old_pwd)
{
	int		find;
	t_env	*tmp;

	find = 0;
	tmp = g_data.g_envlst;
	while (tmp)
	{
		if (!ft_strcmp((tmp)->var, "OLDPWD"))
		{
			(tmp)->val = old_pwd;
			find = 1;
		}
		tmp = (tmp)->next;
	}
	if (!find)
		ft_lstadd_back(&g_data.g_envlst, \
			ft_creat_node(join_add_eq("OLDPWD", old_pwd)));
}

void	modife_enirement_pwd(void)
{
	char	buffer[1024];
	char	*str;
	t_env	*tmp;

	getcwd(buffer, 1024);
	str = ft_strdup(buffer);
	tmp = g_data.g_envlst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->var, "PWD"))
			tmp->val = str;
		tmp = tmp->next;
	}
}

void	ft_built_cd(char **str)
{
	int		i;
	char	*path;
	char	*old_pwd;
	char	s[1024];

	getcwd(s, 1024);
	old_pwd = ft_strdup(s);
	if (!str[1])
	{
		path = find_env("HOME");
		if (!path)
			ft_print_error("HOME");
		i = chdir(path);
	}
	else if (!ft_strcmp(str[1] , "."))
		return ;
	else
		i = ft_get_path(str[1]);
	if (i < 0)
		perror("cd");
	if (i != 1)
		modife_enirement(old_pwd);
	modife_enirement_pwd();
}
