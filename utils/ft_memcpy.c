/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 06:50:03 by codespace         #+#    #+#             */
/*   Updated: 2024/03/12 07:05:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptsrc;
	unsigned char	*ptdst;
	size_t			i;

	i = -1;
	if (!dst && !src)
		return (dst);
	ptsrc = (unsigned char *)src;
	ptdst = (unsigned char *)dst;
	while (++i < n)
	{
		ptdst[i] = ptsrc[i];
	}
	return (dst);
}
