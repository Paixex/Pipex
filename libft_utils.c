/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:21:43 by digil-pa          #+#    #+#             */
/*   Updated: 2023/04/17 16:51:26 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((((unsigned char *)s1)[i]) - ((unsigned char *)s2)[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	k;
	size_t	j;
	char	*substr;

	if (!s)
		return (0);
	k = 0;
	j = start;
	if (start > ft_strlen(s))
	{
		substr = (char *)malloc(sizeof (char));
		*substr = 0;
		return (substr);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	while (j < ft_strlen(s) && k < len)
		substr[k++] = s[j++];
	substr[k] = '\0';
	return (substr);
}

char	triple_strjoin(char *s1, char *s2, char *s3)
{
	int		i;
	char	*res;

	i = 0;
	if(!s1 || !s2 || !s3)
		return(NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	while (*s3)
		res[i++] = *s3++;
	res[i] = 0;
	return (res);		
}