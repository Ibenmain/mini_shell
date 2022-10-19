/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:55:58 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/10/04 00:13:51 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_char_str.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)ft_malloc((ft_strlen(s1) + 1) * sizeof(char), add_garbage_in);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}	
	new[i] = '\0';
	return (new);
}

char	*ft_strdup_out(char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)ft_malloc((ft_strlen(s1) + 1) * \
		sizeof(char), add_garbage_out);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}	
	new[i] = '\0';
	return (new);
}
