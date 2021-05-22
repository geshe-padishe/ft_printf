/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 18:38:53 by user42            #+#    #+#             */
/*   Updated: 2021/05/22 20:04:35 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int						ft_atoi_sign(const char *nstr)
{
	if (nstr[0] == '-')
		return (-1);
	if (nstr[0] == '+')
		return (1);
	return (0);
}

int						ft_atoi(const char *nstr)
{
	unsigned long long int	nbr;
	int						sign;

	sign = 1;
	nbr = 0;
	if ((sign = ft_atoi_sign(nstr)))
		nstr++;
	else
		sign = 1;
	if ((*nstr >= '0' && *nstr <= '9'))
		while (*nstr >= '0' && *nstr <= '9')
		{
			nbr = nbr * 10 + (*nstr - 48);
			nstr++;
		}
	else
		return (0);
	return (nbr * sign);
}
/*
**int main(int argc, char **argv)
**{
**	char *str = argv[1];
**
**	argc = 0;
**	printf("meme => %d\n", ft_atoi(str));
**	printf("real => %d\n", atoi(str));
**	printf("-------\n");
**}
*/
