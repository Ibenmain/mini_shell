/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:24:36 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/10/04 17:54:57 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H

# define BUILTINS_H

char		*creat_tmp_file(char *file);
void		ft_built_pwd(char *str);
void		ft_built_env(void);
void		ft_built_cd(char **str);
void		ft_built_echo(char **str);
int			ft_check_newline(char *str);
void		ft_built_exit(char **str);
int			ft_add_variable(char *cmd);
int			is_valide(char *cmd, int i);
void		sort_and_print(void);
void		ft_print_tab(void);
void		ft_add_to_env(char *var, char *val, bool plus);
void		ft_built_unset(char **str);
void		ft_built_export(char **cmd);
int			is_valide(char *cmd, int i);
int			ft_lstsize(void);
int			ft_its_builtins(t_execlst *data);

#endif