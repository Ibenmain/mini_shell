/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:52:12 by ibenmain          #+#    #+#             */
/*   Updated: 2022/08/29 17:44:43 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/execution.h"
#include "../../includes/libft.h"

void	ft_built_pwd(char *str)
{
	char	s[1000];

	if (*str)
	{
		if (getcwd(s, 1000))
			ft_putendl_fd(s, 1);
		else
			perror("pwd:");
	}
}
