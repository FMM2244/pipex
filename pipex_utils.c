/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:30:57 by fatima            #+#    #+#             */
/*   Updated: 2025/02/14 18:13:48 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pipex.h"

char	*find_command_path(char *cmd, char *envp[])
{
    char *path = NULL;
    for (int i = 0; envp[i] != NULL; i++) {
        if (strncmp(envp[i], "PATH=", 5) == 0) {
            path = envp[i] + 5; // Skip "PATH="
            break;
        }
    }
    if (!path) return NULL; // PATH not found

    char *paths = strdup(path); // Copy PATH variable
	// printf("%s\n", paths);
    char *token = strtok(paths, ":"); // Split by ":"

    char full_cmd[1024]; // Buffer for full path

    while (token) {
        snprintf(full_cmd, sizeof(full_cmd), "%s/%s", token, cmd); // Build path
        if (access(full_cmd, X_OK) == 0) { // Check if executable
            free(paths);
            return strdup(full_cmd); // Return valid path
        }
        token = strtok(NULL, ":");
    }
    free(paths);
    return NULL; // Command not found
}

int	count_no_arg(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i][0] == '-' && !cmd[i])
		i++;
	return (i);
}

void	free_list(char **list)
{
	int	i;

	if (!list)
		return ;
	i = 0;
	while (list[i])
	{
		free(list[i]);
		list[i] = NULL;
		i++;
	}
	free(list);
}

void	break_down_command(char *cmd_input, char **envp)
{
	char	**cmd;
	char	**cmd_arg;
	int		i;

	cmd = ft_split(cmd_input, ' ');
	if (!cmd)
		print_errors(6);
	i = 0;
	cmd_arg = (char **)malloc(count_no_arg(cmd) * sizeof(char *));
	if (!cmd_arg)
		print_errors(7);
	while (*cmd[++i] == '-' && !cmd[i])
	{
		cmd_arg[i - 1] = ft_strdup(cmd[i]);
		if (!cmd_arg)
			print_errors(7);
	}
	cmd_arg[i - 1] = NULL;
	if (execve(find_command_path(cmd[0], envp), cmd_arg, envp) == -1)
		print_errors(8);
	free_list(cmd);
	free_list(cmd_arg);
}

void	print_errors(int flag)
{
	if (flag == 1)
		ft_putendl_fd("Too much or too few arguments", 2);
	else if (flag == 2)
		ft_putendl_fd("Fork failed", 2);
	else if (flag == 3)
		ft_putendl_fd("error opening infile", 2);
	else if (flag == 4)
		ft_putendl_fd("error opening outfile", 2);
	else if (flag == 5)
		ft_putendl_fd("failed to create pipe", 2);
	else if (flag == 6)
		ft_putendl_fd("Error while parsing command", 2);
	else if (flag == 7)
		ft_putendl_fd("Error while allocating memory", 2);
	else if (flag == 8)
		ft_putendl_fd("Failed to execute command", 2);
	exit(EXIT_FAILURE);
}
