/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:46:53 by fmaaita           #+#    #+#             */
/*   Updated: 2024/09/03 20:46:57 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	if (start >= size)
	{
		sub = (char *)malloc(sizeof(char));
		if (sub)
			sub[0] = '\0';
		return (sub);
	}
	if (len > size - start)
		len = size - start;
	sub = malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}
/*
int main(){
	char s[10] = "123456789";
	char *sub;
	sub = ft_substr(s, 1, 0);
	printf("%s", sub);
	return (0);
}
*/
