/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:30:57 by fatima            #+#    #+#             */
/*   Updated: 2025/02/15 11:56:58 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pipex.h"

void	child_process(int in_out_fd[2], int fd[2], char *cmd, char **envp)
{
	// if (in_out_fd[0] == -1)
	// {
	// 	in_out_fd[0] = open("/dev/null", O_RDONLY);
	// 	if (in_out_fd[0] == -1)
	// 		print_errors(3);
	// }
	close(fd[0]);
	dup2(in_out_fd[0], STDIN_FILENO);
	close(in_out_fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	break_down_command(cmd, envp);
}

char	**get_paths(char *cmd, char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	if (!cmd || !envp)
		return (NULL);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

char	*find_command_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*cmd_path;
	char	*temp_path;

	paths = get_paths(cmd, envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		temp_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(cmd_path, X_OK) == 0)
		{
			free_list(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_list(paths);
	return (NULL);
}

int	break_down_command(char *cmd_input, char **envp)
{
	char	**cmd;
	char	*cmd_path;
	int		out;

	cmd = ft_split(cmd_input, ' ');
	if (!cmd)
		print_errors(6);
	cmd_path = find_command_path(cmd[0], envp);
	if (!cmd_path)
	{
		free_list(cmd);
		print_errors(9);
	}
	out = execve(cmd_path, cmd, envp);
	if (out == -1)
		print_errors(8);
	free_list(cmd);
	return (out);
}
