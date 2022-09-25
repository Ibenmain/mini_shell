/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:38:14 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/25 12:15:39 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

char	**ft_cmp_env(t_env *env)
{
	char	**tab;
	t_env	*tmp;
	int		i;
	int		len;

	i = -1;
	tmp = env;
	len = ft_lstsize(env);
	tab = (char **)malloc(sizeof(char *) * len);
	if (!tab)
		return (NULL);
	while (tmp)
	{
		if (tmp->val == NULL)
			tab[++i] = join_add_eq(tmp->var, "");
		else
			tab[++i] = join_add_eq(tmp->var, tmp->val);
		tmp = tmp->next;
	}
	tab[++i] = NULL;
	return (tab);
}

int	is_valide(char *cmd, int i)
{
	if ((cmd[i] && cmd[i] == '+' && cmd[i + 1] != '=')
		|| (cmd[0] && cmd[0] == '=') || (cmd[0] != '_' && !ft_isalpha(cmd[0])))
		return (1);
	return (0);
}

void	ft_add_to_env(char *var, char *val, t_env *env, bool plus)
{
	t_env	*new;
	t_env	*tmp;

	tmp = env;
	new = malloc(sizeof(t_env));
	if (!new)
		return ;
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
	ft_lstadd_back(&env, new);
}

int	ft_add_variable(char *cmd, t_env *env)
{
	char	*var;
	char	*val;
	int		i;

	i = 0;
	while (cmd[i] && cmd[i] != '+' && cmd[i] != '=')
		i++;
	if (is_valide(cmd, i))
		return (printf("Minishell ✗: export: `%s': not a valid identifier\n"\
			, cmd), 0);
	var = ft_substr(cmd, 0, i);
	if (cmd[i] == '\0')
		val = NULL;
	else if (cmd[i] == '+')
		val = ft_substr(cmd, i + 2, ft_strlen(cmd) - i - 2);
	else
		val = ft_substr(cmd, i + 1, ft_strlen(cmd) - i - 1);
	ft_add_to_env(var, val, env, (cmd[i] == '+'));
	return (1);
}

void	ft_built_export(char **cmd, t_env *env)
{
	t_env	*tmp;
	int		i;

	i = 1;
	tmp = env;
	if (!cmd[1])
		sort_and_print(tmp);
	while (cmd[i])
	{
		ft_add_variable(cmd[i], tmp);
		i++;
	}
}
