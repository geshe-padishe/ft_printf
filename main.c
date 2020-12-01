/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotikcho <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:19:31 by nikotikch         #+#    #+#             */
/*   Updated: 2020/12/01 20:24:55 by nikotikch        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int	init_dynarray(t_dynarray *dynarray, uint64_t nb_cells, size_t cell_size)
{
	if (!(dynarray->list = malloc(nb_cells * cell_size)))
		return (-1);
	if (!(dynarray->tmp = malloc(nb_cells * cell_size)))
		return (-1);
	dynarray->cell_size = cell_size;
	dynarray->nb_cells = nb_cells;
	dynarray->byte_size = cell_size * nb_cells;
	return (0);
}

void clear_dynarray(t_dynarray *dynarray, nb_cells)
{
	int i;

	i = 0;
	if (nb_cells > 0)
		while (i < nb_cells)
		{
			dynarray->list[i] = 0;
			dynarray->tmp[i] = 0;
			i++;
		}
	dynarray->cell_size = 0;
	dynarray->nb_cells = 0;
	dynarray->byte_size = 0;
}

int main(int argc, char **argv)
{
	int ret;
	t_dynarray	dynarray;
	(void)argc;

	ret = init_dynarray(&dynarray, (uint64_t)atoi(argv[1]), (size_t)atoi(argv[2]));
	printf("nb_cells of dynarray: %d\n", dynarray.nb_cells);
	printf("cells_size of dynarray: %d\n", dynarray.cell_size);
	printf("byte_size of dynarray: %d\n", dynarray.byte_size);

	//(char*)dynarray.list[0] = 'a';
	//dynarray.list[1] = '\0';
	memcpy(dynarray.list, "a", 2);
	printf("list: %i\n", sizeof(dynarray);
	return (ret);
}
