/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:28:11 by fatima            #+#    #+#             */
/*   Updated: 2025/02/15 14:28:16 by fatima           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pipex.h"

void	check_in_out_files(int fd[2], char **av)
{
	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] == -1)
		print_errors(3);
	fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
	{
		close(fd[0]);
		print_errors(4);
	}
}

void	create_pipe(int fd[2])
{
	int	status;

	status = pipe(fd);
	if (status == -1)
		print_errors(5);
}

void	close_fd(int in_out_fd[2], int fd[2])
{
	close(fd[0]);
	close(fd[1]);
	close(in_out_fd[0]);
	close(in_out_fd[1]);
}

int	create_child_processes(int in_out_fd[2], int fd[2],
		char **av, char **envp)
{
	pid_t	pid1;
	int		status;

	pid1 = fork();
	if (pid1 == -1)
		print_errors(2);
	else if (pid1 == 0)
	{
		close(fd[0]);
		dup2(in_out_fd[0], STDIN_FILENO);
		close(in_out_fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		break_down_command(av[2], envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(in_out_fd[1], STDOUT_FILENO);
		status = break_down_command(av[3], envp);
		close_fd(in_out_fd, fd);
		// wait(NULL);
		waitpid(-1, NULL, 0);
	}
	return (status);
}

int	main(int ac, char **av, char **envp)
{
	int	in_out_fd[2];
	int	fd[2];

	if (ac == 5)
	{
		check_in_out_files(in_out_fd, av);
		create_pipe(fd);
		return (create_child_processes(in_out_fd, fd, av, envp));
	}
	else
		print_errors(1);
	return (0);
}
