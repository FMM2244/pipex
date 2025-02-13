/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:18:39 by fmaaita           #+#    #+#             */
/*   Updated: 2024/09/02 13:21:34 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static long	ne_handler(char *s, long nb)
{
	s[0] = '-';
	return (nb = -nb);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		i;

	nb = n;
	i = ft_numlen(nb);
	s = malloc((i + 1) * sizeof(char));
	if (!s)
	{
		s = NULL;
		return (NULL);
	}
	s[i--] = '\0';
	if (nb < 0)
		nb = ne_handler(s, nb);
	if (nb == 0)
		s[0] = '0';
	while (nb > 0)
	{
		s[i--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (s);
}
/*
int	main(){
	int i = 0;
	char *s; 
	s = ft_itoa(i);
	printf("%s", s);
	return 0;
}
*/
