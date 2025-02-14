/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:13:00 by fmaaita           #+#    #+#             */
/*   Updated: 2024/08/31 15:56:07 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if (i == 0 && c != 0)
		return (NULL);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			break ;
		i--;
	}
	if (i == -1)
		return (NULL);
	return ((char *)(s + i));
}
/*
int main(){
	char s[10] = "123453789";
	char *d;
	int c = 51;
	d = ft_strrchr(s, c);
	printf("%s", d);
	return 0;
}
*/
