/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotikcho <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 00:16:14 by nikotikch         #+#    #+#             */
/*   Updated: 2020/12/04 00:18:45 by nikotikch        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char **argv)
{
	int ret;
	t_dynarray	dynarray;
	(void)argc;

	//secure negative arguments ----> X
	ret = init_dynarray(&dynarray, (uint64_t)atoi(argv[1]), (size_t)atoi(argv[2]));
	ft_memcpy(dynarray.list, "abcd", 5);
	printf("nb_cells of dynarray: %llu\n", dynarray.nb_cells);
	printf("cells_size of dynarray: %zu\n", dynarray.cell_size);
	printf("byte_size of dynarray: %llu\n", dynarray.byte_size);
	printf("list: %s\n\n", dynarray.list);

	//clear_dynarray(&dynarray, dynarray.nb_cells);

	//printf("nb_cells of dynarray: %d\n", dynarray.nb_cells);
	//printf("cells_size of dynarray: %d\n", dynarray.cell_size);
	//printf("byte_size of dynarray: %d\n", dynarray.byte_size);
	//printf("list: %s\n\n", dynarray.list);

	//free_dynarray(&dynarray);
	pop(&dynarray, false);

	printf("nb_cells of dynarray: %llu\n", dynarray.nb_cells);
	printf("cells_size of dynarray: %zu\n", dynarray.cell_size);
	printf("byte_size of dynarray: %llu\n", dynarray.byte_size);
	printf("list: %s\n\n", dynarray.list);

	return (ret);
}
