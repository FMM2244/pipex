/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:52:51 by fmaaita           #+#    #+#             */
/*   Updated: 2024/09/02 11:22:30 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const unsigned char	*ptr;

	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy((char *)ptr, s, ft_strlen(s) + 1);
	return ((char *)ptr);
}
/*
int main (){
	char s1[] = "HiHiHi";
	char *s2;
	s2 = ft_strdup(s1);
	printf("%s", s2);
	return 0;
}
*/
