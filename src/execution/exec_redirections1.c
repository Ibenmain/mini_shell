/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirections1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:48:11 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/10/04 02:07:07 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

char	*get_dlr(char *dlr)
{
	int		i;
	char	*var;

	i = 1;
	while (dlr[i] && !ft_strchr(STR_SPECIAL, dlr[i]) && dlr[i] != '?')
		i++;
	var = getval(dlr, 1, i - 1);
	return (var);
}

char	*expander_hrdc1(char *new, char *del, int *i)
{
	if (!del[*i + 1])
		new = concat(new, "$");
	else if (del[*i + 1] == '+')
	{
		new = concat(new, getval(del, *i, 1));
		while (del[*++i] && del[*i] != '$')
			new = concat(new, getval(del, *i, 1));
		i--;
	}
	else if (del[*i + 1] == '?')
	{
		new = concat(new, ft_itoa(g_data.exit_status));
		i++;
	}
	else
	{
		new = concat(new, get_envval(get_dlr(del + *i)));
		while (del[++(*i)] && (ft_isalnum(del[*i]) || del[*i] == CHR_UNSCR))
			;
		(*i)--;
	}
	return (new);
}

char	*expander_hrdc(char *del)
{
	char	*new;
	int		i;

	i = -1;
	new = NULL;
	while (del[++i])
	{
		if (del[i] == CHR_DLR)
			new = expander_hrdc1(new, del, &i);
		else
			new = concat(new, getval(del, i, 1));
	}
	if (!new)
		return (NULL);
	return (new);
}
