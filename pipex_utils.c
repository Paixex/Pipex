/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:23:25 by digil-pa          #+#    #+#             */
/*   Updated: 2023/04/17 13:24:04 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



void    get_free(char **lst)
{
    int i;

    i = 0;
    if(lst)
    {
        while(lst[i])
            free(lst[i++]);
        free(lst);
    }

}

void    errors (int error)
{
    if(error = 0)
        perror("Invalid number of parameters");
    if(error = 1)
        perror("Error initializing the pipe");
    if(error = 2)
        perror("Error initializing the fork");
    if(error = 3)
        perror("Error reading the infile");
    if(error = 4)
        perror("Error initializing the outfile");
    if(error = 5)
        perror("Path not found");
    if(error = 6)
        perror("Error related to dup2");
    exit(1);
}
