/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_grb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:53:10 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 04:06:42 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_char_str.h"
#include <string.h>

void	add_garbage_in(void *data)
{
	t_grb_clltr	*tmp;

	if (!g_data.g_grb_inside)
	{
		g_data.g_grb_inside = malloc(sizeof(t_grb_clltr));
		if (!g_data.g_grb_inside)
			exit(1);
		g_data.g_grb_inside->value = data;
		g_data.g_grb_inside->next = NULL;
	}
	else
	{
		tmp = g_data.g_grb_inside;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_grb_clltr));
		if (!tmp->next)
			exit(1);
		tmp->next->value = data;
		tmp->next->next = NULL;
	}
}

void	add_garbage_out(void *data)
{
	t_grb_clltr	*tmp;

	if (!g_data.g_grb_outside)
	{
		g_data.g_grb_outside = malloc(sizeof(t_grb_clltr));
		if (!g_data.g_grb_outside)
			exit(1);
		g_data.g_grb_outside->value = data;
		g_data.g_grb_outside->next = NULL;
	}
	else
	{
		tmp = g_data.g_grb_outside;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_grb_clltr));
		if (!tmp->next)
			exit(1);
		tmp->next->value = data;
		tmp->next->next = NULL;
	}
}

void	*ft_malloc(unsigned int size, void (*add_garbage)(void *))
{
	void	*pointer;

	pointer = malloc(size);
	if (!pointer)
		exit(1);
	add_garbage(pointer);
	return (pointer);
}

void	free_grb(t_grb_clltr **collector)
{
	t_grb_clltr	*tmp;

	if (collector && *collector)
	{
		while (*collector)
		{
			tmp = (*collector)->next;
			free((*collector)->value);
			free(*collector);
			*collector = tmp;
		}
	}
}
