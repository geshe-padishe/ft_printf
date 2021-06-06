/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:08:29 by ngenadie          #+#    #+#             */
/*   Updated: 2021/06/06 15:50:17 by ngenadie         ###   ########.fr       */
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
	ret = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("%%\n");
	printf("rl_printf: ");
	ret2 = printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("%%\n");
	printf("my_printf: %d\n", ret);
	printf("rl_printf: %d\n", ret2);
	printf("--------------------------------------------------\n");
//	dprintf(1, "my_printf: ");
//	ret = ft_printf(argv[1], 1);
//	printf("%%\n");
//	printf("rl_printf: ");
//	ret2 = printf(argv[1], 1);
//	printf("%%\n");
//	printf("my_printf: %d\n", ret);
//	printf("rl_printf: %d\n", ret2);

}




//		s2
//		7-16
//		25-27
//		34-36

//		u x X
//		9-13
//		18
//
//		%
//		1-5
//		7
//

//		mix
//		8
//		14
//		28
//


//		s
//		2
//		4-5
//		7-15
//		34-36
//		
//		d
//		16
//		57
//		61
//		65
//		72-74
