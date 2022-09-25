/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:56:07 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/24 17:29:04 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	print_words(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putstr_fd(str[i++], 1);
		if (str[i])
			ft_putstr_fd(" ", 1);
	}
}

int	ft_check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[++i])
	{
		if (str[i] != 'n')
			return (1);
	}
	return (0);
}

void	ft_built_echo(char **str)
{
	int		i;
	int		k;

	if (!str || !*str || ft_strcmp(str[0], "echo"))
		return ;
	i = 1;
	k = 0;
	while (str[i] && str[i][0] == '-')
	{
		if (!ft_check_newline(str[i]))
			k = 1;
		else
			break ;
		i++;
	}
	print_words(&str[i]);
	if (k == 0)
		ft_putstr_fd("\n", 1);
}
