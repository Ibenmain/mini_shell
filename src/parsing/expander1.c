/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:37:01 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/10/04 00:14:33 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

char	*get_envval(char *s)
{
	t_env	*e;

	e = g_data.g_envlst;
	while (e && ft_strcmp(s, e->var))
		e = e->next;
	if (e)
		return (ft_strdup(e->val));
	return (ft_strdup(""));
}
