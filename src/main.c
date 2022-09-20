/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <kfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:11:56 by kfaouzi           #+#    #+#             */
/*   Updated: 2022/08/28 05:47:05 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/execution.h"
#include "../includes/libft.h"
#include<string.h>

void	desplay_shell(void)
{
	char		*line;
	t_tok		*tokens;
	t_execlst	*el;

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
					clear_execlst(&el);
				}
				ft_lstclear(&tokens);
			}
			free(line);
		}
	}
}


int	main(void)
{
	desplay_shell();
}
