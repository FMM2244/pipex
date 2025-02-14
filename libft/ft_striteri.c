/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:18:39 by fmaaita           #+#    #+#             */
/*   Updated: 2024/09/05 15:47:45 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	void	(*fun_ptr)(unsigned int, char*);
	int		i;

	i = 0;
	fun_ptr = f;
	while (*s != 0)
	{
		fun_ptr(i, s);
		i++;
		s++;
	}
}
