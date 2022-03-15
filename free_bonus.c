/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 02:03:57 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/09 18:13:01 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

void	free_path_error(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	exit(-1);
}

void	free_machine(char ***free_me)
{
	int	i;

	i = 0;
	while (free_me[i])
		free_path(free_me[i++]);
	free(free_me);
}

void	ft_free_error(char ***cmds)
{
	free_machine(cmds);
	exit(-1);
}
