/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:31:48 by fmaaita           #+#    #+#             */
/*   Updated: 2025/02/15 19:33:48 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	count_no_arg(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i][0] == '-' && !cmd[i])
		i++;
	return (i);
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
	else if (flag == 9)
	{
		ft_putendl_fd("Command not found", 2);
		exit(127);
	}
	exit(EXIT_FAILURE);
}
