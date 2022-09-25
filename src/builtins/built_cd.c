/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:49:46 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/24 17:46:56 by kfaouzi          ###   ########.fr       */
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

void	modife_enirement(t_env *env, char *pwd)
{
	while (env)
	{
		if (!ft_strcmp(env->var, "OLDPWD"))
			env->val = pwd;
		env = env->next;
	}
}

void	modife_enirement_pwd(t_env *env)
{
	char	buffer[1024];
	char	*str;

	getcwd(buffer, 1024);
	str = ft_strdup(buffer);
	while (env)
	{
		if (!ft_strcmp(env->var, "PWD"))
			env->val = str;
		env = env->next;
	}
}

void	ft_add_oldpwd(t_env **env, char *old_pwd)
{
	ft_lstadd_back(env, ft_creat_node(join_add_eq("OLDPWD", old_pwd)));
}

void	ft_built_cd(char **str, t_env *env)
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
	else
		i = ft_get_path(str[1]);
	if (i == 1)
		ft_add_oldpwd(&env, old_pwd);
	if (i < 0)
		perror("cd");
	modife_enirement(env, old_pwd);
	modife_enirement_pwd(env);
}
