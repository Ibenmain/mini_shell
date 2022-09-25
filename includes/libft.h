/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:02:31 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/24 17:20:32 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include"parsing.h"

char	*getval(char *s, int start, int len);
int		ft_strlen(char *str);
int		ft_strchr(char *s, char c);
char	*ft_strtrim(char *s1, char *set);
int		ft_strcmp(char *s1, char *s2);
char	*concat(char *s1, char *s2);
char	*ft_itoa(int n);
void	free_arr2d(char **arr);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	add_grb(void **content);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int	    ft_atoi(const char *str);
void	ft_lstadd_back(t_env **alst, t_env *new);
int	    ft_lstsize(t_env *lst);
char	*join_add_eq(char *s1, char *s2);
#endif