/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:08:29 by ngenadie          #+#    #+#             */
/*   Updated: 2021/05/24 18:24:27 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int ret;
	int ret2;

//	ret = ft_printf("%42c", 'v');
//	printf("%%\n");
//	ret2 = printf(argv[1], argv[4], argv[5][0]);
	printf("\n");
//	printf("my_printf: %d\n", ret);
//	printf("rl_printf: %d\n", ret2);
	ret = printf(argv[1], argv[2][0], argv[3][0]);
	printf("%%\n");
	printf("rl_printf: %d\n", ret);
}
