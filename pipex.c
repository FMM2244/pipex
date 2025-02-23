/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:29:57 by fmaaita           #+#    #+#             */
/*   Updated: 2025/02/15 19:30:52 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipe(int fd[2])
{
	int	status;

	status = pipe(fd);
	if (status == -1)
		print_errors(5);
}

void	first_child(int in_out_fd[2], int fd[2],
		char **av, char **envp)
{
	in_out_fd[0] = open(av[1], O_RDONLY);
	if (in_out_fd[0] == -1)
	{
		perror(av[1]);
		exit(1);
	}
	close(fd[0]);
	dup2(in_out_fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(in_out_fd[0]);
	break_down_command(av[2], envp);
}

void	second_child(int in_out_fd[2], int fd[2],
		char **av, char **envp)
{
	in_out_fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (in_out_fd[1] == -1)
	{
		perror(av[4]);
		exit(1);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(in_out_fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(in_out_fd[1]);
	break_down_command(av[3], envp);
}

void	create_child_processes(int in_out_fd[2], int pipe_fd[2],
		char **av, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
		print_errors(2);
	if (pid1 == 0)
		first_child(in_out_fd, pipe_fd, av, envp);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			print_errors(2);
		if (pid2 == 0)
			second_child(in_out_fd, pipe_fd, av, envp);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
}

int	main(int ac, char **av, char **envp)
{
	int	in_out_fd[2];
	int	fd[2];

	if (ac == 5)
	{
		create_pipe(fd);
		create_child_processes(in_out_fd, fd, av, envp);
	}
	else
		print_errors(1);
	return (0);
}
