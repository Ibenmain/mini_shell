/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:24:36 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/24 20:32:10 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H

# define BUILTINS_H

char		*creat_tmp_file(char *file);
void		ft_built_pwd(char *str, t_env *env);
void		ft_built_env(t_env *data);
void		ft_built_cd(char **str, t_env *env);
void		ft_built_echo(char **str);
int			ft_check_newline(char *str);
void		ft_built_exit(char **str);
int			ft_add_variable(char *cmd, t_env *env);
int			is_valide(char *cmd, int i);
void		sort_and_print(t_env *env);
void		ft_print_tab(t_env *env);
void		ft_add_to_env(char *var, char *val, t_env *env, bool plus);
void		ft_built_unset(char **str, t_env *data);
void		ft_built_export(char **cmd, t_env *env);
int			is_valide(char *cmd, int i);
int			ft_lstsize(t_env *lst);
int			ft_its_builtins(t_execlst *data, t_env *env);

#endif