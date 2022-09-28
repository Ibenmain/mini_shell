/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:54:52 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/28 16:59:36 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	handle_redirection(t_red *red)
{
	int	fd;

	if (red->type == REDIN || red->type == HEREDC)
	{
		fd = open(red->file, O_RDONLY);
		if (fd < 0)
			return (0);
		dup2(fd, 0);
		close(fd);
		if (red->type == HEREDC)
			unlink(red->file);
	}
	else
	{
		if (red->type == APPND)
			fd = open(red->file, O_APPEND | O_CREAT | O_WRONLY, 0666);
		else
			fd = open(red->file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd < 0)
			return (0);
		dup2(fd, 1);
		close(fd);
	}
	return (1);
}

int	redirection(t_red *red)
{
	while (red)
	{
		if (!handle_redirection(red))
		{
			error_msg("Minisehll: ", red->file, ": No such file or directory");
			return (0);
		}
		red = red->next;
	}
	return (1);
}
