/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:41:02 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/24 22:39:44 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	cmd_valide(char *cmd)
{
	int		i;

	i = -1;
	if (!ft_isalpha(cmd[0]))
		return (1);
	while (cmd[++i])
	{
		if ((47 < cmd[0] && cmd[0] < 58) || !ft_isalnum(cmd[i]))
			return (1);
	}
	return (0);
}

void	ft_delete_element(char *cmd, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (!ft_strcmp(cmd, tmp->var))
	{
		tmp = env->next;
		return ;
	}
	if (cmd_valide(cmd))
		printf("Minishell ✗: unset: `%s': not a valid identifier\n"\
			, cmd);
	while (tmp)
	{
		if (tmp->next && !ft_strcmp(cmd, tmp->next->var))
			tmp->next = tmp->next->next;

		tmp = tmp->next;
	}
}

void	ft_built_unset(char **str, t_env *data)
{
	t_env	*tmp;
	int		i;

	tmp = data;
	i = 0;
	if (!str || !*str)
		return ;
	while (str[++i])
		ft_delete_element(str[i], tmp);

}
