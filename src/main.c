/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:11:56 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/21 10:45:24 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/execution.h"
#include "../includes/libft.h"
#include<string.h>

void	desplay_shell(t_tok *tokens, t_execlst *el, char **data)
{
	char	*line;
	t_env	*env;

	env = init_env(data);
	if (!env)
		return ;
	while (1)
	{
		line = readline(STR_PROMPT);
		if (line)
		{
			if (line[0])
			{
				add_history(line);
				line = ft_strtrim(line, STR_SPC);
				tokens = tokenizer(line);
				if (!check_syntax(tokens))
				{
					el = get_execlst(tokens);
					ft_executer_cmd(el, env);
					clear_execlst(&el);
				}
				ft_lstclear(&tokens);
			}
			free(line);
		}
	}
}

int	main(int argc, char **argv, char **data)
{
	t_tok		tokens;
	t_execlst	el;

	(void)argc;
	(void)argv;
	desplay_shell(&tokens, &el, data);
}
