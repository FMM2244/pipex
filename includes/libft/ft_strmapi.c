/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:09:56 by fmaaita           #+#    #+#             */
/*   Updated: 2024/09/05 13:10:27 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	(*fun_ptr)(unsigned int, char);
	char	*temp;	
	int		i;

	i = 0;
	fun_ptr = f;
	temp = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (temp == NULL)
		return (0);
	while (*s != 0)
	{
		temp[i] = fun_ptr(i, *s);
		i++;
		s++;
	}
	temp[i] = 0;
	return (temp);
}
/*
char	fun(unsigned int i, char c)
{
	c = c + i;
	return (c);
}

int main (){
	char    (*fun_ptr)(unsigned int, char) = &fun;
	char	s[] = "987654321";
	printf("%s", ft_strmapi(s, fun_ptr);
	return 0;
}
*/
