/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:11:56 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/09/29 13:29:06 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_char_str.h"
#include <string.h>

void	print_env(t_env *e);
void	print_redcmd(t_execlst	*e);

void	handel_signal(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	desplay_shell(void)
{
	char		*line;
	t_tok		*tokens;
	t_execlst	*el;

	signal(SIGINT, handel_signal);
	signal(SIGQUIT, SIG_IGN);
	rl_catch_signals = 0;
	while (1)
	{
		line = readline(STR_PROMPT);
		if (!line)
		{
			write (1, " exit\n", 5);
			exit(0);
		}
		if (line[0])
		{
			add_history(line);
			line = ft_strtrim(line, STR_SPC);
			tokens = tokenizer(line);
			if (!check_syntax(tokens))
			{
				el = get_execlst(tokens);
				if (el)
				{
					el = expand_list(el);
					ft_executer_cmd(el);
					//print_redcmd(el);
				}
			}
		}
	}
}

int	main(int argc, char **av, char **env_)
{
	(void)argc;
	(void)av;
	g_data.g_envlst = init_env(env_);
	//print_env(g_data.g_envlst);
	desplay_shell();
}

void	print_env(t_env *e)
{
	t_env	*tmp = e;

	printf("****************************env*********************************\n");
	while (tmp)
	{
		printf("%s(%d)=%s(%d)\n", tmp->var, tmp->sz_var, tmp->val, tmp->sz_val);
		tmp = tmp->next;
	}
	printf("****************************env*********************************\n\n\n");
}

void	print_redcmd(t_execlst	*e)
{
	t_execlst	*el = e;

	printf("****************************cmdred*********************************\n");
	while (el)
	{
		int i = -1;
		printf("cmd : ");
		while (el->cmd && el->cmd[++i])
			printf("%s ", el->cmd[i]);
		printf("\nred : ");
		while (el->red)
		{
			printf("%s(%d) ", el->red->file, el->red->type);
			el->red = el->red->next;
		}
		el = el->next;
		printf("\n");
	}
	printf("****************************cmdred*********************************\n\n");
}
