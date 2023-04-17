/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:25:23 by digil-pa          #+#    #+#             */
/*   Updated: 2023/04/17 16:55:17 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*--------------------------------------------------------*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*--------------------------------------------------------*/

//Prototypes

char	triple_strjoin(char *s1, char *s2, char *s3);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

#endif