/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:43:19 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/14 19:37:55 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (argv[i])
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			if (argv[i][j++] == 39)
				flag++;
		}
		if (flag % 2 != 0)
		{
			write(2, "quote not close\n", 17);
			exit(1);
		}
		i++;
	}
}

void	create_aux_file(char *argv, char ***cmds)
{
	int		fd;
	char	*str;
	char	*endoffile;

	fd = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	str = get_next_line(0);
	endoffile = ft_strjoin(argv, "\n");
	while (ft_strncmp(str, endoffile, 100) != 0)
	{
		write(fd, str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
		if (!str)
			ft_free_error(cmds);
	}
	close(fd);
	free(str);
	free(endoffile);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	***cmds;
	int		status;

	if (!envp)
		exit(1);
	else if (argc < 5)
		return (1);
	else if (ft_strncmp(argv[1], "here_doc", 10) == 0 && argc < 6)
		return (1);
	check_args(argv);
	cmds = get_cmd(argv, argc);
	if (ft_strncmp(argv[1], "here_doc", 10) == 0)
	{
		create_aux_file(argv[2], cmds);
		status = pipex("here_doc", argv[argc - 1], cmds, envp);
		unlink("here_doc");
	}
	else
		status = pipex(argv[1], argv[argc - 1], cmds, envp);
	free_machine(cmds);
	return (status);
}
