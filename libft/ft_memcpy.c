/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:37:59 by fmaaita           #+#    #+#             */
/*   Updated: 2024/08/29 09:38:20 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*temp_s;
	unsigned char		*temp_d;

	if (!dest && !src)
		return (0);
	temp_s = (unsigned const char *)src;
	temp_d = (unsigned char *)dest;
	while (n--)
		*temp_d++ = *temp_s++;
	return (dest);
}
/*
int main (){
	printf("%s\n", (char *)ft_memcpy("           ", "fatimahalafarah", 17));
	return 0;
}*/
