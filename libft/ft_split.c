/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:23:23 by                   #+#    #+#             */
/*   Updated: 2021/10/22 18:23:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*malloctrouble(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	word_count(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char	*words_mem_alloc(const char *s, char c)
{
	char	*splited_word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	splited_word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != c)
	{
		splited_word[i] = s[i];
		i++;
	}
	splited_word[i] = '\0';
	return (splited_word);
}

char	**ft_split(const char *s, char c)
{
	char	**splited;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	splited = (char **)malloc(word_count(s, c) * sizeof(char *) + 1);
	if (!splited)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			splited[i] = words_mem_alloc(s, c);
			if (!splited[i])
				malloctrouble(splited);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	splited[i] = NULL;
	return (splited);
}
