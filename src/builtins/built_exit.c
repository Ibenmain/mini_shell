/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:56:07 by ibenmain          #+#    #+#             */
/*   Updated: 2022/10/04 00:20:34 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_other_exit(char	**str)
{
	if (!str[1])
	{
		printf("%s\n", str[0]);
		exit(g_data.exit_status);
	}
	if (ft_is_number(str[1]))
	{
		error_msg("Minishell: exit: ", str[1], \
			": numeric argument required");
		exit(255);
	}
}

void	ft_built_exit(char **str)
{
	int		status;
	int		argc;

	argc = 0;
	status = 0;
	if (!str || !*str)
		return ;
	while (str[argc])
		argc++;
	if (argc > 2 && !ft_is_number(str[1]))
	{
		ft_putendl_fd(str[0], 2);
		error_msg("Minishell: exit: too many arguments", NULL, NULL);
		g_data.exit_status = 1;
	}
	else
	{
		ft_other_exit(str);
		status = ft_atoi(str[1]);
		printf("%s\n", str[0]);
		exit(status);
	}
}
