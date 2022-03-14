/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:06:01 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/14 14:53:28 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

char	**ft_split(char const *s1, char c);
char	**ft_split_cmds(char const *s1, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_machine(char ***free_me);
void	ft_free_error(char ***cmds);
void	free_path(char **paths);
char	***get_cmd(char **argv, int argc);
char	*ft_strchr(const char *s, int c);
int		pipex(char *file1, char *file2, char ***cmds, char **envp);
char	*get_path(char **envp, char *cmd1);
int		get_status(pid_t pid, int cmd_nbr);
void	free_path_error(char **paths);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, const char *s2);
#endif