/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirections1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:48:11 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/26 12:10:33 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

char	*creat_tmp_file(char *file)
{
	char	*new;
	char	*path;
	int		inc;
	int		ex;

	if (!file)
		file = "";
	inc = 0;
	new = NULL;
	ex = 1;
	while (ex != -1 && inc <= 2147483647)
	{
		new = concat(".", file);
		new = concat(new, ft_itoa(inc));
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

char *expander_hrdc(char *del)//TODO handel $ $? $$
{
	char	*new;
	int		i;

	i = -1;
	new = NULL;
	while (del[++i])
	{
		if (del[i] == CHR_DLR)
		{
			new = concat(new, get_envval(del + i));
			while (del[++i] && (ft_isalnum(del[i]) || del[i] == CHR_UNSCR))
				;
			i--;
		}
		else
			new = concat(new, getval(del, i, 1));
	}
	if (!new)
		return (NULL);
	return (new);
}

void	put_in_fd(char *del, int fd, int nbdel)
{
	if (nbdel)
	{
		del = expander_hrdc(del);
		ft_putstr_fd(del, fd);
	}
	else
		ft_putstr_fd(del, fd);
}

char	*exec_hrdc(char *fle, int delmtr)
{
	char	*file;
	char	*del;
	int		ex;
	int		fd;

	file = creat_tmp_file(fle);
	if (!file)
		return (NULL);
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC);
	if (fd == -1)
		perror("ERROR : ");//TODO exit status
	ex = 1;
	while (ex)
	{
		del = readline("> ");//TODO FREE
		if (!del)
			return (NULL);//TODO readline return
		ex = ft_strcmp(del, fle);
		if (ex)
		{
			del = concat(del, "\n");
			put_in_fd(del, fd, delmtr);
		}
	}
	return (close(fd), file);
}
