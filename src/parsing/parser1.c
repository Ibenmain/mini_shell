/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:59:56 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/21 21:06:38 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	exist_pipe(t_tok *token)
{
	t_tok	*tmp;

	if (token)
	{
		tmp = token;
		while (tmp)
		{
			if (tmp->type == PIPE)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

int	check_syntax(t_tok *token)
{
	int	v;

	v = 0;
	if (exist_pipe(token))
		v = check_pipe(&token);
	while (!v && token && (token->type == WORD || token->type == D_QTE \
		|| token->type == S_QTE))
	{
		if (check_str(token->value))
			return (printf(STR_QTERR), 1);
		token = token->next;
	}
	if (!v && (token && token->type == RED))
		v = check_red(&token);
	if (!v && (token && token->type == PIPE && !token->next))
		return (printf(STR_PERR));
	return (v);
}

int	help_pipe(t_tok **token)
{
	int	v;

	v = 0;
	if ((*token)->type != WORD && (*token)->type != D_QTE \
		&& (*token)->type != S_QTE && (*token)->type != RED)
		return (printf(STR_PERR));
	if ((*token)->type == RED)
	{
		if (check_red(&(*token)))
			return (1);
	}
	else
	{
		while (*token && ((*token)->type == WORD || \
			(*token)->type == D_QTE || (*token)->type == S_QTE))
		{
			if (check_str((*token)->value))
				return (printf(STR_QTERR), 1);
			*token = (*token)->next;
		}
	}
	return (v);
}

int	check_pipe(t_tok **token)
{
	int	v;

	v = 0;
	while (*token)
	{
		v = help_pipe(&(*token));
		if (v)
			return (1);
		if (*token && ((*token)->type == PIPE && !(*token)->next))
			return (printf(STR_PERR));
		if (*token && (*token)->type == PIPE)
			*token = (*token)->next;
	}
	return (v);
}

int	check_red(t_tok **token)
{
	int	v;

	v = 0;
	while (*token && (*token)->type == RED)
	{
		*token = (*token)->next;
		if (!*token || ((*token)->type != WORD && (*token)->type != D_QTE \
			&& (*token)->type != S_QTE))
			return (printf(STR_REDERR), 1);
		while (*token && ((*token)->type == WORD || (*token)->type == D_QTE \
			|| (*token)->type == S_QTE))
		{
			v = check_str((*token)->value);
			if (v)
				return (printf(STR_QTERR), 1);
			*token = (*token)->next;
		}
	}
	return (v);
}
