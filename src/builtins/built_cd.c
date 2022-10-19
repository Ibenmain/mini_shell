/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:49:46 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 02:16:05 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	ft_get_path(char *cmd)
{
	char	*path;
	int		i;

	if (!ft_strcmp(cmd, "-"))
	{
		path = find_env("OLDPWD");
		if (!path)
			return (error_msg("minishell: cd: ", "OLDPWD", " not set"), 1);
		printf("%s\n", path);
		i = chdir(path);
	}
	else if (!ft_strcmp(cmd, "~"))
	{
		path = find_env("HOME");
		if (!path)
			return (error_msg("minishell: cd: ", "HOME", " not set"), 0);
		i = chdir(path);
	}
	else
		i = chdir(cmd);
	return (i);
}

void	change_enirement(char *old_pwd)
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

void	change_enirement_pwd(void)
{
	char	buffer[1024];
	char	*str;
	t_env	*tmp;

	getcwd(buffer, 1024);
	str = ft_strdup_out(buffer);
	tmp = g_data.g_envlst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->var, "PWD"))
			tmp->val = str;
		tmp = tmp->next;
	}
}

void	ft_change_pwd_oldpwd(int i, char *old_pwd)
{
	if (i < 0)
		perror("cd");
	if (i != 1)
		change_enirement(old_pwd);
	change_enirement_pwd();
}

void	ft_built_cd(char **str)
{
	int		i;
	char	*path;
	char	*old_pwd;
	char	s[1024];

	getcwd(s, 1024);
	old_pwd = ft_strdup_out(s);
	if (!str[1])
	{
		path = find_env("HOME");
		if (!path)
			error_msg("minishell: cd: ", "HOME", " not set");
		i = chdir(path);
	}
	else if (!ft_strcmp(str[1], "."))
	{
		if (!getcwd(old_pwd, 1024))
			error_msg(STR_MSG_ERROR, NULL, NULL);
		return ;
	}
	else
		i = ft_get_path(str[1]);
	ft_change_pwd_oldpwd(i, old_pwd);
}
