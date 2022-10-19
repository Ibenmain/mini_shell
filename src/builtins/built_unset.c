/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:41:02 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 00:06:57 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	cmd_valide(char *cmd)
{
	int		i;

	i = -1;
	if (cmd[0] != '_' && !ft_isalpha(cmd[0]))
		return (1);
	while (cmd[++i])
	{
		if (cmd[i] == '_' || ft_isalnum(cmd[i]))
			continue ;
		else
			return (1);
	}
	return (0);
}

t_env	*ft_delete_element(char *cmd)
{
	t_env	*tmp;
	t_env	*tp;
	t_env	*tmp_fr;

	tmp = g_data.g_envlst;
	tp = g_data.g_envlst;
	if (!ft_strcmp(cmd, tp->var))
	{
		tmp = tmp->next;
		return (tmp);
	}
	if (cmd_valide(cmd))
		error_msg("Minishell ✗: unset: `", cmd, "': not a valid identifier");
	while (tmp)
	{
		if (tmp->next && !ft_strcmp(cmd, tmp->next->var))
		{
			tmp_fr = tmp->next;
			tmp->next = tmp->next->next;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (g_data.g_envlst);
	return (tmp);
}

void	ft_built_unset(char **str)
{
	int		i;

	i = 0;
	if (!str || !*str || !g_data.g_envlst)
		return ;
	while (str[++i])
		g_data.g_envlst = ft_delete_element(str[i]);
}
