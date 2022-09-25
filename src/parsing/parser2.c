/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:11:22 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/21 21:06:41 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

t_tok	*lstnew(char *content, t_enum type)
{
	t_tok	*element;

	if (!content)
		return (NULL);
	element = (t_tok *)malloc(sizeof(t_tok));
	if (!element)
		return (NULL);
	element->value = content;
	element->type = type;
	element->next = NULL;
	return (element);
}

int	add_tkn(t_tok **token, t_tok *new)
{
	t_tok	*tmp;

	if (!new)
		return (1);
	if (token)
	{
		if (*token == NULL)
		{
			*token = new;
			new = NULL;
		}
		else
		{
			tmp = *token;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
			tmp = NULL;
			new = NULL;
		}
	}
	return (0);
}

void	ft_lstclear(t_tok **lst)
{
	t_tok	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free((*lst)->value);
			free(*lst);
			*lst = tmp;
		}
	}
}