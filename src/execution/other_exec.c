/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:33:46 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/25 21:53:05 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

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

char	*get_path(char *cmd)
{
	char	*path;
	char	**tab;
	char	*retn;
	int		i;

	i = -1;
	retn = NULL;
	if (!cmd || !*cmd || !g_data.g_envlst)
		return (NULL);
	path = find_env("PATH");
	tab = ft_split(path, ':');
	while (tab[++i])
	{
		if (tab[i])
		{
			tab[i] = ft_add_slache(tab[i], '/');
			tab[i] = concat(tab[i], cmd);
			if (!retn)
				retn = tab[i];
		}
		else
			return (NULL);
	}
	return (retn);
}

char	**ft_copy_env(void)
{
	char	**tab;
	t_env	*tmp;
	int		i;
	int		len;

	i = -1;
	tmp = g_data.g_envlst;
	len = ft_lstsize();
	tab = (char **)malloc(sizeof(char *) * len + 1);
	if (!tab)
		return (NULL);
	while (tmp)
	{
		tab[++i] = join_add_eq(tmp->var, tmp->val);
		if (tab[i] == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	tab[++i] = NULL;
	return (tab);
}
