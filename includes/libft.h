/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:02:31 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/20 10:31:09 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include<stdio.h>
#include<stdbool.h>
# include<stdlib.h>
# include<string.h>
# include<unistd.h>
# include <signal.h>
# include<fcntl.h>
# include "utils_char_str.h"
# include "readline/readline.h"
# include "readline/history.h"
# include "execution.h"
# include "libft.h"
# include "parsing.h"

char	*getval(char *s, int start, int len);
int		ft_strlen(char *str);
int		ft_strchr(char *s, char c);
char	*ft_strtrim(char *s1, char *set);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
char	*concat(char *s1, char *s2);
char	*ft_itoa(int n);
void	free_arr2d(char **arr);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int 	ft_isalpha(int c);
#endif