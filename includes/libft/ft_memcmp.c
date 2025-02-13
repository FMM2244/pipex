/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:00:47 by fmaaita           #+#    #+#             */
/*   Updated: 2024/08/31 19:50:45 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char const	*temp1;
	unsigned char const	*temp2;

	temp1 = s1;
	temp2 = s2;
	if (n == 0)
		return (0);
	n = n - 1;
	while (*temp1 == *temp2 && n--)
	{
		temp1++;
		temp2++;
	}
	return (*temp1 - *temp2);
}
/*
int main(){
	char s[10] = "123456789";
	char t[10] = "123456789";	
	int d;
	d = ft_memcmp(s, t, 9);
	printf("%d", d);
	return 0;
}
*/
