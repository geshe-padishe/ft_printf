/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:08:29 by ngenadie          #+#    #+#             */
/*   Updated: 2021/06/02 19:38:46 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main(int argc, char **argv)
{
	int ret;
	int ret2;
	conv whoopty;

	dprintf(1, "my_printf: ");
	ret = ft_printf(argv[1], argv[2]);
	printf("%%\n");
	printf("rl_printf: ");
	ret2 = printf(argv[1], argv[2]);
	printf("%%\n");
	printf("my_printf: %d\n", ret);
	printf("rl_printf: %d\n", ret2);
}











//		s
//		2
//		4-5
//		7-15
//		34-36
//		
//		d
//		1
//		13-14
//		16-18
//		45-47
//		49-51
//		53-55
//		57-59
//		61-63
//		65-68
//		72-74
//		81-83
