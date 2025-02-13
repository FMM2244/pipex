/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:53:26 by fmaaita           #+#    #+#             */
/*   Updated: 2024/08/31 16:04:56 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dst);
	if (len >= size)
		return (ft_strlen(src) + size);
	i = 0;
	while (i < size - len - 1 && src[i] != '\0')
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (ft_strlen(src) + len);
}
/*
int main() {
	char s1[50] = "jack is stupid";
	char s2[] = "hi! I'm jack";
	size_t j = ft_strlcpy(s1, s2, 12);
	printf("%s\n", s1);
	printf("%s\n%ld", s2, j);
	return 0;
}
*/
