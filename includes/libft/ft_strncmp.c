/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:33:08 by fmaaita           #+#    #+#             */
/*   Updated: 2024/08/31 16:48:03 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && n-- >= 1 && *s1 && *s2)
	{	
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*
#include<stdio.h>
int main(){
	char s[10] = "123453789";
	char t[10] = "789456132";	
	int d;
	d = strncmp(s, t, 5);
	printf("%d", d);
	return 0;
}
*/
