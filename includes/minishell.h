/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:01:10 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/08/26 19:53:14 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "utils_char_str.h"
# include "readline/readline.h"
# include "readline/history.h" 

t_tok	*tokenizer(char *l);
int		skipword(char *line);
int		skipquotes(char *line);
int		skiptkn(char *line);

int		check_str(char *l);
int		check_red(t_tok **token);
int		check_pipe(t_tok **token);
int		check_syntax(t_tok *token);

t_execlst	*get_execlst(t_tok *tkns);
t_execlst	*getred(t_execlst *e, t_tok *tok);
char	*exec_hrdc(t_red *red);
t_red	*getredlst(t_red *red, t_tok *tok);
t_enum	get_redtype(char *val);
t_execlst	*getcmd(t_execlst *e, char *val);
t_execlst	*init_execlst(void);


void	clear_execlst(t_execlst **lst);
#endif 