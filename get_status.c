/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:48:08 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/09 19:20:30 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_status(pid_t pid, int cmd_nbr)
{
	int	status;

	waitpid(pid, &status, 0);
	while (cmd_nbr--)
		wait(NULL);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (WSTOPSIG(status));
}
