/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:18:59 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/10/04 03:46:56 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	stay_in_shell(int _signal)
{
	if (SIGINT == _signal && g_data.id_cat == 0)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
		g_data.id_cat = 0;
}

void	handel_sig_hr(int _signal)
{
	(void)_signal;
	g_data.exec = -1;
	rl_done = 1;
}
