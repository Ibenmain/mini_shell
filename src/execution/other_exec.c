/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:33:46 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 17:02:14 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

char	*ft_add_slache(char *cmd, char c)
{
	char	*tmp;
	int		len;

	if (!cmd)
	{
		tmp = ft_malloc(sizeof(char *) * 2, add_garbage_in);
		tmp[0] = c;
		tmp[1] = '\0';
		return (tmp);
	}
	len = ft_strlen(cmd);
	tmp = ft_malloc(sizeof(char *) * len + 2, add_garbage_in);
	ft_strlcpy(tmp, cmd, len + 1);
	tmp[len] = c;
	tmp[len + 1] = '\0';
	return (tmp);
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
	tab = (char **)ft_malloc(sizeof(char *) * (len + 1), add_garbage_in);
	if (!tab || !tmp)
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
