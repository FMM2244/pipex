/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:50:43 by fmaaita           #+#    #+#             */
/*   Updated: 2024/08/31 19:00:14 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	x;

	temp = (unsigned char *)s;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (temp[i] == x)
			return (temp + i);
		i++;
	}
	return (NULL);
}
/*
int main(){
	char s[10] = "123456789";
	char *d;
	int c = 51;
	d = ft_memchr(s, c, 2);
	printf("%s", d);
	return 0;
}
*/
