/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:12:21 by digil-pa          #+#    #+#             */
/*   Updated: 2023/05/10 18:09:23 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
		pipex(av, envp);
	else
		errors(0);
	return(0);
}

void pipex(char **av, char **envp)
{
	int	pipe_id;
	int	pipe_fd[2];

	if (pipe(pipe_fd))
		errors(1);
	pipe_id = fork();
	if (pipe_id < 0)
		errors(2);
	if (!pipe_id)
}

void	first(char **envp, char **av, int *pipefd)
{
	char *str;
	char **avsplit;
	int infile;

	close(pipefd[0]);
	infile = open(av[1], O_RDONLY)
	if (infile < 0)
		errors(3);
	if (dup2(infile, STDIN_FILENO) < 0)
		errors(6);
	if (dup2(infile, STDOUT_FILENO) < 0)
		errors(6);
	avsplit = ft_split(av[2], ' ');
	str = getpath(envp, avsplit[0]);
	execve(str, avsplit, envp);
	get_free(avsplit);
	free(str);
	exit(4);
}

void	second(char **envp, char **av, int *pipefd)
{
	char	*str;
	char	**avsplit;
	int		outfile;
	
	close(pipefd[1]);
	outfile = open(av[4] | O_WRONLY | O_CREAT | O_TRUNC);
	if (outfile < 0)
		errors(4);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		erros(6);
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
		errors(6);
	avsplit = ft_split(av[3], ' ');
	str = getpath(envp, avsplit[0]);
	get_free(avsplit);
	free(str);
	exit(4);
}
