/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:29:11 by fmaaita           #+#    #+#             */
/*   Updated: 2024/08/30 18:52:09 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include<stdio.h>
int main(){
	char s1[50] = "jack is stupid";
	char s2[] = "hi! I'm jack";
	size_t j = ft_strlcpy(s1, s2, 12);
	printf("%s\n", s1);
	printf("%s\n%ld", s2, j);
	return 0;
}
*/
