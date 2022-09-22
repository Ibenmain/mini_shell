/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:11:56 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/22 19:10:18 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/execution.h"
#include "../includes/libft.h"
#include<string.h>

// t_env	*add_to_envirenemt()
// {
// 	t_env	*head;

// 	head = NULL;
// 	ft_lstadd_back(&head, ft_creat_node(ft_strjoin("PWD", getcwd(NULL, 0))));
// 	ft_lstadd_back(&head, ft_creat_node(ft_strjoin("SHLVL", "1")));
// 	// ft_lstadd_back(&head, ft_creat_node(ft_strjoin("_", "/usr/bin/env")));
// 	return (head);
// }

void	desplay_shell(t_tok *tokens, t_execlst *el, char **data)
{
	char	*line;
	t_env	*env;

	env = init_env(data);
	// if (!env)
	// 	env = add_to_envirenemt();
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
