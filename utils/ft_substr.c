/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:58:44 by codespace         #+#    #+#             */
/*   Updated: 2024/02/26 18:59:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		s_len;

	if (!s)
		return (NULL);
	if (!s || !*s)
		len = 0;
	else
	{
		s_len = ft_strlen(s);
		if (s_len < len)
			len = s_len - start;
		if ((start + len) > s_len)
			len--;
		if (s_len < start || (len == (unsigned long)-1))
			len = 0;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
		*(str + len) = *(s + start + len);
	return (str);
}