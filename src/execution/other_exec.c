/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:33:46 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/24 01:34:17 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

char	*ft_add_slache(char *cmd, char c)
{
	char	*tmp;
	int		len;

	if (!cmd)
	{
		tmp = malloc(sizeof(char *) * 2);
		tmp[0] = c;
		tmp[1] = '\0';
		return (tmp);
	}
	len = ft_strlen(cmd);
	tmp = malloc(sizeof(char *) * len + 2);
	ft_strlcpy(tmp, cmd, len + 1);
	tmp[len] = c;
	tmp[len + 1] = '\0';
	return (tmp);
}

char	*get_path(char *cmd, t_env *env)
{
	char	*path;
	char	**tab;
	char	*retn;
	int		i;

	i = -1;
	retn = NULL;
	if (!cmd || !*cmd || !env)
		return (NULL);
	path = find_env("PATH", env);
	tab = ft_split(path, ':');
	while (tab[++i])
	{
		tab[i] = ft_add_slache(tab[i], '/');
		tab[i] = concat(tab[i], cmd);
		if (!retn)
			retn = tab[i];
	}
	return (retn);
}

char	**ft_copy_env(t_env *env)
{
	char	**tab;
	t_env	*tmp;
	int		i;
	int		len;

	i = -1;
	tmp = env;
	len = ft_lstsize(env);
	tab = (char **)malloc(sizeof(char *) * len + 1);
	if (!tab)
		return (NULL);
	while (tmp)
	{
		tab[++i] = ft_strjoin(tmp->var, tmp->val);
		tmp = tmp->next;
	}
	tab[++i] = NULL;
	return (tab);
}
