/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:02:31 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/10/04 15:07:13 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include"parsing.h"

int		ft_strlen(char *l);
char	*getval(char *s, int start, int len);
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
char	*ft_substr_out(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		ft_atoi(const char *str);
char	*ft_itoa_out(int n);
void	ft_lstadd_back(t_env **alst, t_env *new);
char	*join_add_eq(char *s1, char *s2);
char	*ft_strdup_out(char *s1);
void	add_garbage_in(void *data);
void	add_garbage_out(void *data);
void	free_grb(t_grb_clltr **data);
int		ft_nbrlen(long int n);
void	put_miness(long int *v, char *_case);
int		ft_count(char *str, char d);
char	*ft_strdupout(char *s1);
char	**ft_other_split_out(char *s, char c, int i, int j);
char	**ft_split_out(char *s, char c);
#endif