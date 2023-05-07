/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:23:25 by digil-pa          #+#    #+#             */
/*   Updated: 2023/05/07 16:22:25 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	getpath(char **envp, char	*command)
{
	int		i;
	char	**paths;
	char	*str;

	if (!command || !access(command, F_OK))
		return (command);
	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		str = triple_strjoin(paths[i++], "/", command);
		if (!access(str, F_OK))
			break ;
		free(str);
		str = NULL;
	}
	if (!str)
		errors(5);
	free(paths);
	return (str);
}

void	get_free(char **list)
{
	int		i;

	i = 0;
	if (list)
	{
		while (list[i])
			free (list[i++]);
		free (list);
	}
}

void	errors(int error)
{
	if (error == 0)
		perror ("Invalid number of parameters");
	if (error == 1)
		perror ("Error initializing the pipe");
	if (error == 2)
		perror ("Error initializing the fork");
	if (error == 3)
		perror ("Error reading the infile");
	if (error == 4)
		perror ("Error initializing the outfile");
	if (error == 5)
		perror ("Path not found");
	if (error == 6)
		perror ("Error related to dup2");
	exit (1);
}
