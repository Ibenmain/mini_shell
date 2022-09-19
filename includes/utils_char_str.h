/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char_str.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:33:48 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/08/29 18:41:21 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_CHAR_STR_H

# define UTILS_CHAR_STR_H

# define CHR_SPC ' '
# define CHR_OUTR '>'
# define CHR_INR '<'
# define CHR_PIPE '|'
# define CHR_S_QT '\''
# define CHR_D_QT '\"'
# define CHR_END '\0' 
# define CHR_EQL '=' 

# define STR_SPC " "
# define STR_OUTR ">"
# define STR_INR "<"
# define STR_APND ">>"
# define STR_HRDC "<<"

# define STR_TKN_VALS "><|\"\' "

# define STR_PROMPT "Minishell ✗ "
# define STR_PERR "Minishell: syntax error near unexpected token ` | '\n"
# define STR_QTERR "Minishell: syntax error in unexpected token `quotes'\n"
# define STR_REDERR "Minishell: syntax error near unexpected token `newline'\n"

#endif