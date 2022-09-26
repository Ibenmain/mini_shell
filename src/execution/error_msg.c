/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:10:22 by ibenmain          #+#    #+#             */
/*   Updated: 2022/09/26 13:37:00 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	error_msg(char *str1, char *str2, char *str3)
{

	if (str1 && str2 && str3)
		ft_putendl_fd(concat(concat(str1, str2), str3), 2);
	if (str2 == NULL && str3 == NULL)
		ft_putendl_fd(str1, 2);
	if (str3 == NULL)
		ft_putstr_fd(concat(str1, str2), 2);
	g_data.exit_status = 1;
}
