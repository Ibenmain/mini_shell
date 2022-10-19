/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:38:14 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 15:07:27 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	is_valide(char *cmd, int i)
{
	if ((cmd[i] && cmd[i] == '+' && cmd[i + 1] != '=')
		|| (cmd[0] && cmd[0] == '=') || (cmd[0] != '_' && !ft_isalpha(cmd[0])))
		return (1);
	return (0);
}

void	ft_add_to_env(char *var, char *val, bool plus)
{
	t_env	*new;
	t_env	*tmp;

	tmp = g_data.g_envlst;
	new = ft_malloc(sizeof(t_env), add_garbage_out);
	while (tmp)
	{
		if ((tmp->var) && !ft_strcmp(tmp->var, var))
		{
			if (plus && val)
				tmp->val = concat(tmp->val, val);
			else if (!val)
				return ;
			else
				tmp->val = val;
			return ;
		}
		tmp = tmp->next;
	}
	new->var = var;
	new->val = val;
	new->next = NULL;
	ft_lstadd_back(&g_data.g_envlst, new);
}

int	ft_add_variable(char *cmd)
{
	char	*var;
	char	*val;
	int		plus;
	int		i;

	i = 0;
	plus = 0;
	while (cmd[i] && cmd[i] != '+' && cmd[i] != '=')
		i++;
	if (is_valide(cmd, i))
		return (error_msg("Minishell ✗: export: `", cmd, \
			"': not a valid identifier"), 0);
	var = ft_substr(cmd, 0, i);
	if (cmd[i] == '\0')
		val = NULL;
	else if (cmd[i] == '+')
	{
		plus = 1;
		val = ft_substr(cmd, i + 2, ft_strlen(cmd) - i - 2);
	}
	else
		val = ft_substr(cmd, i + 1, ft_strlen(cmd) - i - 1);
	ft_add_to_env(var, val, plus);
	return (1);
}

void	ft_built_export(char **cmd)
{
	int		i;

	i = 1;
	if (!cmd[1])
		sort_and_print();
	while (cmd[i])
	{
		ft_add_variable(cmd[i]);
		i++;
	}
}
