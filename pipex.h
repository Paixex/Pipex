/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:25:23 by digil-pa          #+#    #+#             */
/*   Updated: 2023/05/07 17:12:09 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*--------------------------------------------------------*/

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <sys/wait.h>

/*--------------------------------------------------------*/

//Prototypes

char			triple_strjoin(char *s1, char *s2, char *s3);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *str);
static int		ft_letter_count(char const *s, char c);
static int		ft_word_count(char const *s, char c);
static char		*ft_stralloc(char **strs, char const *s, int *i, char c);
char			**ft_split(char const *s, char c);
void			get_free(char **list);
char			getpath(char **envp, char	*command);
void			errors(int error);

#endif