/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr_int.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 18:33:57 by bprado         #+#    #+#                */
/*   Updated: 2019/12/11 22:02:13 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_strchr_int(const char *s, int c)
{
	ssize_t		i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
		if (c == 0 && s[i] == 0)
			return (i);
	}
	return (-1);
}
