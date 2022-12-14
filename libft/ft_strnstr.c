/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:42:38 by kyoda             #+#    #+#             */
/*   Updated: 2022/09/04 01:40:28 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	c;
	size_t	tmp_len;

	c = *needle;
	tmp_len = ft_strlen(needle);
	if (haystack == NULL && len == 0)
		return (NULL);
	if (*needle != '\0')
	{
		while (1)
		{
			while (*(haystack++) != c)
			{
				if (len-- < 1 || *(haystack - 1) == '\0')
					return (NULL);
			}
			if (tmp_len > len--)
				return (NULL);
			if (ft_strncmp((haystack - 1), needle, tmp_len) == 0)
				break ;
		}
		haystack--;
	}
	return ((char *)haystack);
}
