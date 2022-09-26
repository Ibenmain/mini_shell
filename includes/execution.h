/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 07:38:40 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/26 12:17:58 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H

# define EXECUTION_H
# include"libft.h"
# include"parsing.h"

int			ft_index_key(char *data);
char		*creat_tmp_file(char *file);
char		*exec_hrdc(char *fle, int delmtr);

char		*ft_key(char *data);
char		*ft_val(char *data);
t_env		*ft_creat_node(char *data);
t_env		*init_env(char **env);
char		*expander(char *line, char *wd, int i);
t_execlst	*expand_list(t_execlst *el);
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

void	    error_msg(char *str1, char *str2, char *str3);

#endif