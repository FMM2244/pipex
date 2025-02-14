/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:19:58 by fmaaita           #+#    #+#             */
/*   Updated: 2024/09/04 10:29:53 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc((len1 + len2 + 1) * sizeof(char));
	i = 0;
	if (new == NULL)
		return (NULL);
	while (*s1 != 0)
	{
		new[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != 0)
	{
		new[i] = *s2;
		i++;
		s2++;
	}
	new[i] = 0;
	return (new);
}
/*
int main(){
	char s1[] = "";
	char s2[] = "";
	char *new;
	new = ft_strjoin(s1, s2);
	printf("%s", new);
	return 0;
}
*/
