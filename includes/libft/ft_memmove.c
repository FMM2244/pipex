/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:43:30 by fmaaita           #+#    #+#             */
/*   Updated: 2024/08/31 15:57:30 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*temp_s;
	unsigned char		*temp_d;

	if (!dest && !src)
		return (0);
	temp_s = src;
	temp_d = dest;
	if (temp_d > temp_s)
		while (n--)
			temp_d[n] = temp_s[n];
	else
		while (n--)
			*temp_d++ = *temp_s++;
	return (dest);
}
