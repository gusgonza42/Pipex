/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:52:30 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/18 13:53:58 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * ((i + j) + 1));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	res[i + j] = '\0';
	while (j--)
		res[i + j] = s2[j];
	while (i--)
		res[i] = s1[i];
	free(s1);
	return (res);
}
