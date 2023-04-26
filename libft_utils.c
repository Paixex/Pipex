/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:21:43 by digil-pa          #+#    #+#             */
/*   Updated: 2023/04/26 12:45:01 by digil-pa         ###   ########.fr       */
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

static int	ft_letter_count(char const *s, char c)
{
	size_t	k;

	k = 0;
	while (s[k] != '\0' && s[k] != c)
		k++;
	return (k);
}

static int	ft_word_count(char const *s, char c)
{
	int	k;
	int	onof;
	int	word;

	k = 0;
	onof = 1;
	word = 0;
	while (s[k] != '\0')
	{
		if (onof == 1 && s[k] != c)
		{
			word++;
			onof = 0;
		}
		else if (s[k] == c)
			onof = 1;
		k++;
	}
	return (word);
}

static char	*ft_stralloc(char **strs, char const *s, int *i, char c)
{
	int		k;
	char	*str;

	k = 0;
	str = (char *)malloc(sizeof(char) * (ft_letter_count(s + *i, c) + 1));
	if (!strs || !str)
		return (NULL);
	while (s[*i] != '\0' && s[*i] != c)
	{
		str[k] = s[*i];
		k++;
		(*i)++;
	}
	str[k] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		k;
	int		count;

	k = 0;
	count = 0;
	strs = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!strs)
		return (NULL);
	while (s[k] != '\0')
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		if (s[k] != '\0')
		{
			strs[count] = ft_stralloc(strs, s, &k, c);
			count++;
		}
	}
	strs[count] = 0;
	return (strs);
}