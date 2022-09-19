/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirections1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:48:11 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/08/28 16:33:27 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/execution.h"

char	*creat_tmp_file(char *file)
{
	char	*new;
	char	*path;
	int		inc;
	int		ex;

	if (!file || (file && !file[0]))
		file = "\n";
	inc = 0;
	new = NULL;
	ex = 1;
	while (ex != -1 && inc <= 2147483647)
	{
		new = concat(file, ".");
		new = concat(file, ft_itoa(inc));
		if (!new)
			return (NULL);
		path = concat("/tmp/", new);
		if (!path)
			return (NULL);
		ex = access(path, F_OK);
		inc++;
	}
	return (path);
}

char	*exec_hrdc(t_red *red)//TODO handel ' and "
{
	char	*file;
	char	*del;
	int		ex;
	int		fd;

	if (!red->file)
		red->file = "";
	file = creat_tmp_file(red->file);
	if (!file)
		return (NULL);
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC);
	if (fd == -1)
		perror("ERROR : ");
	ex = 1;
	while (ex)
	{
		del = readline("> ");
		if (!del)
			break ;
		ex = ft_strcmp(del, file);
		if (ex)
		{
			del = concat(del, "\n");
			ft_putstr_fd(del, fd);
		}
	}
	close(fd);
	return (file);
}
