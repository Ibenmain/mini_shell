/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:56:07 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/25 22:13:49 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	print_words(char **str, int k)
{
	int	i;

	i = 1;
	if (k == 1)
		i = 2;
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
	char	*tmp;

	i = 1;
	k = 0;
	if (!str || !*str || ft_strcmp(str[0], "echo"))
		return ;
	while (str[i])
	{
		tmp = str[i];
		if (str[i][0] == '-' && str[i][1] == 'n')
		{
			if (!ft_check_newline(str[i]))
				k = 1;
		}
		if (str[i][0] == '~' && str[i][1] == '\0')
				str[i] = ft_strdup(find_env("HOME"));
		else if (str[i][0] == '~' && str[i][1] == '/')
		{
				str[i] = ft_strdup(find_env("HOME"));
				str[i] = ft_add_slache(str[i], '/');
				str[i] = concat(str[i], \
					ft_substr(tmp, i + 1, ft_strlen(tmp) - i));
		}
		i++;
	}
	print_words(&(*str), k);
	if (k == 0)
		ft_putstr_fd("\n", 1);
}
