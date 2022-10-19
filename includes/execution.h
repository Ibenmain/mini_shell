/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 07:38:40 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/10/04 18:03:32 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H

# define EXECUTION_H
# include"libft.h"
# include"parsing.h"
# include <errno.h>

int			ft_index_key(char *data);
char		*creat_tmp_file(char *file);
char		*ft_key(char *data);
char		*ft_val(char *data);
t_env		*ft_creat_node(char *data);
t_env		*init_env(char **env);
char		*get_envval(char *s);
char		*find_env(char *path);
char		*ft_get_path_of_cmd(char *word);
void		exec_other_cmd(t_execlst *data, int fd[]);
void		ft_cmd_to_exec(t_execlst *el);
int			check_access(t_execlst *el);
void		ft_executer_cmd(t_execlst *el);
char		*ft_add_slache(char *cmd, char c);
char		*get_path(char *cmd);
char		**ft_copy_env(void);
int			handle_red(t_red *red);
int			redirection(t_red *red);
void		error_msg(char *str1, char *str2, char *str3);
int			check_access(t_execlst *el);
void		exec_other_cmd(t_execlst *data, int fd[]);
char		*ft_get_path_of_cmd(char *word);
void		stay_in_shell(int _signal);
void		handel_sig_hr(int _signal);
int			ft_not_exist(char *str, t_env *head);
#endif
