/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:44:05 by mshazaib          #+#    #+#             */
/*   Updated: 2024/03/11 06:13:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*f;
	int				i;

	i = -1;
	f = (unsigned char *)b;
	while (++i < (int)len)
		f[i] = c;
	return (b);
}
