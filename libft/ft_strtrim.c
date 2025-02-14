/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:49:19 by fmaaita           #+#    #+#             */
/*   Updated: 2024/09/04 11:27:36 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isthere(char const *s, char c)
{
	while (*s != c && *s != 0)
		s++;
	if (*s == 0)
		return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(s1);
	j = len - 1;
	i = 0;
	while (i <= j)
	{
		if (!isthere(set, s1[i]) && !isthere(set, s1[j]))
			return ((char *)ft_substr(s1, i, j - i + 1));
		if (isthere(set, s1[i]))
			i++;
		if (isthere(set, s1[j]))
			j--;
	}
	if (isthere(set, s1[i]))
		return (ft_strdup(""));
	return (ft_strdup(s1));
}
/*
int main(){
	printf("%s", ft_strtrim("asdaskdasd", "asd"));
	return 0;
}
*/
