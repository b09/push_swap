/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 17:53:20 by bprado        #+#    #+#                 */
/*   Updated: 2019/01/21 17:04:03 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char*)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size + 1] = 0;
	while (size)
	{
		str[size] = 0;
		--size;
	}
	str[0] = 0;
	return (str);
}
