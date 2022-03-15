/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:52:05 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/14 16:53:07 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	***get_cmd(char **argv, int argc)
{
	char	***cmds;
	int		i;
	int		j;

	if (ft_strncmp("here_doc", argv[1], 10) == 0)
		i = 3;
	else
		i = 2;
	j = 0;
	cmds = malloc(sizeof(char ***) * argc - 2);
	if (!cmds)
		exit(5);
	while (i < argc - 1)
		cmds[j++] = ft_split_cmds(argv[i++], ' ');
	cmds[j] = NULL;
	return (cmds);
}
