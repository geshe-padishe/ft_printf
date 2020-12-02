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

void my_memcpy(void *ptr, void *ptr2, uint64_t n)
{
	size_t	i;
	char	*uptr;
	char	*uptr2;

	uptr = ptr;
	uptr2 = ptr2;

	i = 0;
	while (i < n)
	{
		uptr[i] = uptr2[i];
		i++;
	}
}

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

void clear_dynarray(t_dynarray *dynarray, uint64_t nb_cells)
{
	uint64_t	i;
	char		*list = dynarray->list;
	char		*tmp = dynarray->tmp;

	i = 0;
	if (nb_cells > 0)
		while (i < nb_cells)
		{
			list[i] = 0;
			tmp[i] = 0;
			i++;
		}
	dynarray->cell_size = 0;
	dynarray->nb_cells = 0;
	dynarray->byte_size = 0;
}

void free_dynarray(t_dynarray *dynarray)
{
	if (dynarray != NULL)
	{
		if (dynarray->list != NULL)
			free(dynarray->list);
		if (dynarray->tmp != NULL)
			free(dynarray->tmp);
	}
}

int push_dynarray(t_dynarray *dynarray, void *new_cells, uint64_t new_byte_size, int direction)
{
	char *tmp;

	tmp = dynarray->tmp;
	free(tmp);
	printf("dyn_byte_size: %llu, new_byte-size: %llu\n", dynarray->byte_size, new_byte_size);
	if (!(tmp = malloc(dynarray->byte_size + new_byte_size)))
		return (-1);
	printf("tmp add: %p, tmp + (..) add: %p\n", (void*)tmp, (void*)(tmp + new_byte_size));
	if (direction == 1)
	{
		printf("bye\n");
		my_memcpy((void*)tmp, new_cells, new_byte_size);
		my_memcpy((void*)(tmp + new_byte_size), dynarray->list, dynarray->byte_size);
	}
	else
	{
		printf("hello\n");
		my_memcpy((void*)tmp, dynarray->list, dynarray->byte_size);
		my_memcpy((void*)(tmp + dynarray->byte_size), new_cells, new_byte_size);
	}
	free(dynarray->list);
	dynarray->list = tmp;
	tmp = NULL;
	if (!(tmp = malloc(dynarray->byte_size + new_byte_size)))
		return (-1);
	dynarray->byte_size += new_byte_size;
	dynarray->nb_cells += (new_byte_size / dynarray->cell_size);
	return (0);
}

int main(int argc, char **argv)
{
	int ret;
	t_dynarray	dynarray;
	(void)argc;

	//secure negative arguments ----> X
	ret = init_dynarray(&dynarray, (uint64_t)atoi(argv[1]), (size_t)atoi(argv[2]));
	my_memcpy(dynarray.list, "aaa", 4);
	printf("nb_cells of dynarray: %d\n", dynarray.nb_cells);
	printf("cells_size of dynarray: %d\n", dynarray.cell_size);
	printf("byte_size of dynarray: %d\n", dynarray.byte_size);
	printf("list: %s\n\n", dynarray.list);

	//clear_dynarray(&dynarray, dynarray.nb_cells);

	//printf("nb_cells of dynarray: %d\n", dynarray.nb_cells);
	//printf("cells_size of dynarray: %d\n", dynarray.cell_size);
	//printf("byte_size of dynarray: %d\n", dynarray.byte_size);
	//printf("list: %s\n\n", dynarray.list);

	//free_dynarray(&dynarray);
	push_dynarray(&dynarray, "bbb", 3, 2);

	printf("nb_cells of dynarray: %d\n", dynarray.nb_cells);
	printf("cells_size of dynarray: %d\n", dynarray.cell_size);
	printf("byte_size of dynarray: %d\n", dynarray.byte_size);
	printf("list: %s\n\n", dynarray.list);

	return (ret);
}
