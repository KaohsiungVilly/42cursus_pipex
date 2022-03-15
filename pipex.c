/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:17:48 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/15 12:36:39 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp, char *cmd1)
{
	char	**all_paths;
	char	*check_path;
	int		i;

	while (ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	i = -1;
	if (ft_strncmp(cmd1, "/", 1) == 0)
		return (cmd1);
	*envp = ft_substr(*envp, 5, INT_MAX);
	all_paths = ft_split(envp[++i], ':');
	cmd1 = ft_strjoin("/", cmd1);
	check_path = ft_strjoin(*all_paths, cmd1);
	while (access(check_path, F_OK) != 0 && all_paths[++i])
	{
		free(check_path);
		check_path = ft_strjoin(all_paths[i], cmd1);
	}
	free(cmd1);
	free_path(all_paths);
	free(*envp);
	return (check_path);
}

void	ft_first_cmd(char *file, int pfd[2], char ***cmds, char **envp)
{
	int	fd;

	close(pfd[0]);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "could not open input file\n", 26);
		free_machine(cmds);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	dup2(pfd[1], STDOUT_FILENO);
	close(fd);
	close(pfd[1]);
	if (execve(get_path(envp, cmds[0][0]), cmds[0], envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(127);
	}
}

int	ft_cmd_exec(char ***cmds, int cmd_nbr, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_free_error(cmds);
	pid = fork();
	if (pid == -1)
		ft_free_error(cmds);
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (execve(get_path(envp, cmds[cmd_nbr][0]), cmds[cmd_nbr], envp))
		{
			write(2, "command not found\n", 18);
			free_machine(cmds);
			exit(127);
		}
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	return (cmd_nbr + 1);
}

int	ft_lst_cmd(char *file, char ***cmds, int cmd_nbr, char **envp)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_free_error(cmds);
	if (pid == 0)
	{
		if (access("here_doc", F_OK) == 0)
			fd = open(file, O_CREAT | O_RDWR | O_APPEND);
		else
			fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd < 0)
			exit(1);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		if (execve(get_path(envp, cmds[cmd_nbr][0]), cmds[cmd_nbr], envp) == -1)
		{
			write(2, "command not found\n", 18);
			free_machine(cmds);
			exit(127);
		}
	}
	return (pid);
}

int	pipex(char *file1, char *file2, char ***cmds, char **envp)
{
	int		pfd[2];
	int		status;
	int		cmd_nbr;
	pid_t	pid;

	if (pipe(pfd) == -1)
		ft_free_error(cmds);
	pid = fork();
	if (pid == -1)
		ft_free_error(cmds);
	else if (pid == 0)
		ft_first_cmd(file1, pfd, cmds, envp);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	cmd_nbr = 1;
	while (cmds[cmd_nbr] && cmds[cmd_nbr + 1])
		cmd_nbr = ft_cmd_exec(cmds, cmd_nbr, envp);
	pid = ft_lst_cmd(file2, cmds, cmd_nbr, envp);
	close(STDIN_FILENO);
	status = get_status(pid, cmd_nbr);
	return (status);
}
