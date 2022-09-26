/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:37:01 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/26 22:21:39 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

char	*getsqts_val(char *s)
{
	int		i;
	char	*s_qts;

	i = -1;
	while (s[++i] && s[i] != CHR_S_QT)
		;
	s_qts = malloc(i + 1);
	if (!s_qts)
		return (NULL);
	s_qts[i] = CHR_END;
	while (--i >= 0 && s[i] != CHR_S_QT)
		s_qts[i] = s[i];
	return (s_qts);
}

char	*get_envval(char *s)
{
	t_env	*e;
	int		i;
	char	*var;

	i = 0;
	while (s[++i] && (ft_isalnum(s[i]) || s[i] == CHR_UNSCR))
		;
	if (s[i] == '?')
		return (ft_itoa(g_data.exit_status));
	var = getval(s, 1, i - 1);
	if (!var)
		return (NULL);
	e = g_data.g_envlst;
	while (e && ft_strcmp(var, e->var))
		e = e->next;
	if (e)
		return (e->val);
	return ("");
}

int	check_qts(char *s, int i, int flg)
{
	if (flg == 1)
		return (s[i] && ((s[i] != CHR_D_QT && s[i] != CHR_S_QT) || \
			(s[i] == CHR_S_QT && s[0] == CHR_D_QT)));
	return (s[i] && ((s[i] != CHR_D_QT && s[i] != CHR_S_QT) || \
		(s[i] == CHR_S_QT && s[0] == CHR_D_QT)) && s[i] != CHR_DLR);
}

void	skip(char c, int *i)
{
	if (*i == 0 && c == CHR_D_QT)
		*i += 1;
	else if (c == '?')
		*i += 1;
}

char	*getdqts_val(int i, char *s, char *d_qts)
{
	int		k;

	// if (s[i] == CHR_D_QT)
	// 	i++;
	skip(s[i], &i);
	while (check_qts(s, i, 1))
	{
		if (s[i] == CHR_DLR)
		{
			d_qts = concat(d_qts, get_envval(s + i));
			while (s[++i] && (ft_isalnum(s[i]) || s[i] == CHR_UNSCR))
				;
			// if (s[i] == '?')
			// 	i++;
			skip(s[i], &i);
		}
		else
		{
			k = i;
			while (check_qts(s, i, 2))
				i++;
			d_qts = concat(d_qts, getval(s, k, i - k));
		}
		if (!d_qts)
			return (NULL);
	}
	if (!d_qts)
		d_qts = STR_STRNULL;
	return (d_qts);
}

char	*expander(char *line, char *wd, int i)
{
	while (wd && wd[i])
	{
		if (wd[i] == CHR_S_QT)
		{
			line = concat(line, getsqts_val(wd + (i + 1)));
				while (wd[++i] && wd[i] != CHR_S_QT)
					;
		}
		else if (wd[i] == '~')
			line = concat(line, find_env("HOME"));
		else
		{
			line = concat(line, getdqts_val(0, wd + i, NULL));
			if (wd[i] == CHR_D_QT)
				while (wd[++i] && wd[i] != CHR_D_QT)
					;
			else
				while (wd[i + 1] && wd[i + 1] != CHR_D_QT && wd[i + 1] != CHR_S_QT)
					i++;
		}
		i++;
		if (!line)
			return (NULL);
	}
 	return (line);
}