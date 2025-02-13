/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:32:17 by fmaaita           #+#    #+#             */
/*   Updated: 2024/08/29 09:32:48 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1024);
	return (0);
}
/*
#include<stdio.h>
#include<ctype.h>
int main(){
	int c;
	scanf("%d", &c);
	printf("%d\n", ft_isalpha(c));
	printf("%d\n", ft_isdigit(c));
	printf("%d\n", ft_isascii(c));
	printf("%d\n", ft_isprint(c));
	printf("%d\n", ft_isalnum(c));
	printf("==================\n");
	printf("%d\n", isalpha(c));
	printf("%d\n", isdigit(c));
	printf("%d\n", isascii(c));
	printf("%d\n", isprint(c));
	printf("%d\n", isalnum(c));
	return 0;
}
*/
