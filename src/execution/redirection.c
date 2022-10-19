/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:54:52 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 18:39:17 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	handle_redirection(t_red *red)
{
	if (red->fd < 0)
		return (0);
	if (red->type == REDIN || red->type == HEREDC)
	{
		dup2(red->fd, 0);
		close(red->fd);
	}
	else
	{
		dup2(red->fd, 1);
		close(red->fd);
	}
	return (1);
}

int	redirection(t_red *red)
{
	while (red)
	{
		if (!handle_redirection(red))
		{
			if (!access(red->file, F_OK))
				error_msg("Minisehll: ", red->file, ": Permission denied");
			else
				error_msg("Minisehll: ", red->file, \
					": No such file or directory");
			return (0);
		}
		red = red->next;
	}
	return (1);
}
