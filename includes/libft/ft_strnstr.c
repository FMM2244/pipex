/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:52:57 by fmaaita           #+#    #+#             */
/*   Updated: 2024/09/01 15:32:24 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size;

	size = ft_strlen(little);
	if (size == 0)
		return ((char *)big);
	if (!(ft_strncmp(big, "", ft_strlen(big))) || len == 0 || size > len)
		return (NULL);
	while (*big != '\0' && len-- >= size)
	{
		if (*big == *little)
			if (!ft_strncmp(big, little, size))
				return ((char *)big);
		big++;
	}
	return (NULL);
}
/*
#include<stdio.h>
#include<string.h>
int main()
{

    char    *s1 = "MZIRIBMZIRIBMZE123";
    char    *s2 = "MZIRIBMZ";

    char    *i2 = ft_strnstr(s1, s2, 8);

    printf("ft_strnstr: %s\n", i2);
    return 0;
}
*/
