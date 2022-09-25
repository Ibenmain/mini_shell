/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:56:07 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/24 22:29:52 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	ft_built_exit(char **str)
{
	int		status;
	int		argc;

	argc = 0;
	if (!str || !*str)
		return ;
	while (str[argc])
		argc++;
	if (argc - 1 >= 2)
	{
		printf("%s\n", str[0]);
		printf("Minishell: exit: too many arguments\n");
	}
	else
	{
		if (!str[1])
		{
			printf("%s\n", str[0]);
			exit(0);
		}
		status = ft_atoi(str[1]);
		printf("%s\n", str[0]);
		exit(status);
	}
}
