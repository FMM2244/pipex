/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatima <fatima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:28:11 by fatima            #+#    #+#             */
/*   Updated: 2025/02/14 18:13:14 by fatima           ###   ########.fr       */
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
		print_errors(4);
}

void	create_pipe(int fd[2])
{
	int	status;

	status = pipe(fd);
	if (status == -1)
		print_errors(5);
}

void	create_child_processes(int in_out_fd[2], int fd[2],
		char **av, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	pid1 = fork();
	if (pid1 == -1)
		print_errors(2);
	dup2(in_out_fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	break_down_command(av[2], envp);
	pid2 = fork();
	if (pid2 == -1)
		print_errors(2);
	dup2(fd[0], STDIN_FILENO);
	dup2(in_out_fd[1], STDOUT_FILENO);
	break_down_command(av[3], envp);
	close(fd[0]);
	close(fd[1]);
	close(in_out_fd[0]);
	close(in_out_fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}

int	main(int ac, char **av, char **envp)
{
	int	in_out_fd[2];
	int	fd[2];

	if (ac == 5)
	{
		check_in_out_files(in_out_fd, av);
		create_pipe(fd);
		create_child_processes(in_out_fd, fd, av, envp);
	}
	else
		print_errors(1);
	return (0);
}
