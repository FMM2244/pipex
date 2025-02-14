/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:20:40 by fmaaita           #+#    #+#             */
/*   Updated: 2024/09/04 17:27:45 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_of_wo(char const*s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static int	num_of_ch(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i + 1);
}

static char	**ft_fr(char **list)
{
	int	i;

	i = -1;
	while (list[++i] != 0)
	{
		free(list[i]);
		list[i] = NULL;
	}
	free(list);
	list = NULL;
	return (list);
}

static char	*setter(char *s, char c, char *list)
{
	int	index;

	index = 0;
	while (*s != c && *s != 0)
	{
		list[index] = *s;
		index++;
		s++;
	}
	list[index] = 0;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	int		l_in;
	int		no_words;

	if (!s)
		return (NULL);
	no_words = num_of_wo(s, c);
	l_in = -1;
	list = (char **)malloc((no_words + 1) * sizeof(char *));
	if (list == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			list[++l_in] = malloc(num_of_ch(s, c) * sizeof(char));
			if (list[l_in] == NULL)
				return (ft_fr(list));
			s = setter((char *)s, c, list[l_in]);
		}
		else
			s++;
	}
	list[no_words] = NULL;
	return (list);
}
/*
int main(){
	char s[] = "hello!";
	char **v;
	v = ft_split(s, ' ');
	for (int i = 0; v[i] != NULL; i++)
		printf("%s", v[i]);
	return 0;
}
*/
