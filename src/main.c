/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:11:56 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/10/04 18:26:32 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_char_str.h"
#include <string.h>

void	token_and_exec(char *line, t_tok *tokens, t_execlst *el)
{
	line = ft_strtrim(line, STR_SPC);
	tokens = tokenizer(line);
	if (!check_syntax(tokens))
	{
		el = get_execlst(tokens);
		if (el)
		{
			g_data.exec = 1;
			el = expand_list(el);
			if (g_data.exec == 1)
				ft_executer_cmd(el);
		}
	}
}

void	desplay_shell(char *line, t_tok *tokens, t_execlst *el)
{
	(void)tokens;
	(void)el;
	while (1)
	{
		line = readline(STR_PROMPT);
		if (!line)
		{
			write (1, " exit\n", 6);
			free_grb(&g_data.g_grb_inside);
			exit(0);
		}
		if (line[0])
		{
			add_history(line);
			token_and_exec(line, NULL, NULL);
			free_grb(&g_data.g_grb_inside);
		}
		free(line);
	}
	free_grb(&g_data.g_grb_outside);
}

void	run_minishell(void)
{
	signal(SIGINT, stay_in_shell);
	signal(SIGQUIT, SIG_IGN);
	rl_catch_signals = 0;
	desplay_shell(NULL, NULL, NULL);
}

int	main(int argc, char **av, char **env_)
{
	(void) argc;
	(void) av;
	g_data.pwd = getcwd(NULL, 0);
	g_data.g_envlst = init_env(env_);
	run_minishell();
	return (0);
}
