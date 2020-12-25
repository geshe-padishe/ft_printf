/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotikcho <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 00:16:14 by nikotikch         #+#    #+#             */
/*   Updated: 2020/12/16 13:50:45 by nikotikch        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>
#include <assert.h>

//int test_(void)
//{
//	
//	return (0);
//}
//int test_(void)
//{
//
//	return (0);
//}
int test_dynarray_insert(void)
{
	t_dynarray dynarray;
//	char *list;
//	char *tmp;

	init_dynarray(&dynarray, (uint64_t)4, (size_t)1);
	push_dynarray(&dynarray, "abc\0", 4, true);
	dyn_insr(&dynarray, "123", 2, 3);

	printf("list after insert: %s\n", dynarray.list);
	assert(dyn_insr(NULL, "123", 2, 3) == -1);
	assert(dyn_insr(&dynarray, NULL, 2, 3) == -1);
	assert(dyn_insr(&dynarray, "123", 2, 0) == -1);
	assert(dyn_insr(&dynarray, "123", 100, 4) == -1);
	return (0);
}

int test_dynarray_extract(void)
{
	t_dynarray dynarray;
	char *list;
	char *tmp;

	init_dynarray(&dynarray, (uint64_t)4, (size_t)1);
	push_dynarray(&dynarray, "abcd", 4, true);

	dynarray_extract(&dynarray, 2, 1);
	list = dynarray.list;
	tmp = dynarray.tmp;
	assert(list[2] == 'd');
	assert(dynarray.nb_cells == 3);

	dynarray_extract(&dynarray, 2, 1);
	list = dynarray.list;
	tmp = dynarray.tmp;
	assert(list[1] == 'b');
	assert(dynarray.nb_cells == 2);

	dynarray_extract(&dynarray, 1, 1);
	list = dynarray.list;
	tmp = dynarray.tmp;
	assert(list[0] == 'a');
	assert(dynarray.nb_cells == 1);


	assert(dynarray_extract(NULL, 5, 3) == -1);
	assert(dynarray_extract(&dynarray, 4, 7) == -1);
	assert(dynarray_extract(&dynarray, 0, 10) == -1);
	return (0);
}

int test_push_dynarray(void)
{
	t_dynarray dynarray;
	char *list;
	char *tmp;

	init_dynarray(&dynarray, (uint64_t)4, (size_t)1);
	list = dynarray.list;
	tmp = dynarray.tmp;

	assert(push_dynarray(NULL, "3\0", 2, false) == -1);
	assert(push_dynarray(&dynarray, NULL, 2, false) == -1);
	assert(push_dynarray(&dynarray, "3\0", 0, false) == -1);

	printf("byte_size: %llu\n", dynarray.byte_size);
	push_dynarray(&dynarray, "abcd", 4, true);
	printf("byte_size: %llu\n", dynarray.byte_size);

	list = dynarray.list;
	tmp = dynarray.tmp;
	assert(list[0] == 'a');

	printf("nb_cells: %llu\n", dynarray.nb_cells);
	printf("byte_size: %llu\n", dynarray.byte_size);
	printf("list add: %p\n", dynarray.list);
	push_dynarray(&dynarray, "3\0", 2, false);
	printf("list add: %p\n", dynarray.list);

	list = dynarray.list;
	tmp = dynarray.tmp;
	printf("nb_cells: %llu\n", dynarray.nb_cells);
	printf("byte_size: %llu\n", dynarray.byte_size);
	assert(list[5] == '\0');

	push_dynarray(&dynarray, "33", 2, true);

	list = dynarray.list;
	tmp = dynarray.tmp;
	assert(list[0] == '3');

	return (0);
}

int test_pop_dynarray(void)
{
	t_dynarray dynarray;

	init_dynarray(&dynarray, 10, 1);
	memcpy(dynarray.list, "kishta123", 10);
	dynarray.nb_cells += 10;
	pop_dynarray(&dynarray, 1, true);
	assert(((char*)dynarray.list)[0] == 'i');
	pop_dynarray(&dynarray, 2, true);
	assert(((char*)dynarray.list)[0] == 'h');
	pop_dynarray(&dynarray, 10, true);
	assert(((char*)dynarray.list)[0] == 'h');
	return (0);
}

int test_free_dynarray(void)
{
	t_dynarray dynarray;

	init_dynarray(&dynarray, 10, 10);
	free_dynarray(&dynarray);
	assert(dynarray.list == NULL);
	assert(dynarray.tmp == NULL);
	assert(dynarray.cell_size == 0);
	assert(dynarray.byte_size == 0);
	assert(dynarray.nb_cells == 0);
	return (0);
}

int test_init_dynarray(void)
{
	t_dynarray dynarray;

	assert(init_dynarray(NULL, 10, 10) == -1);
	assert(init_dynarray(&dynarray, 10, 10) == 0);
	assert(dynarray.cell_size == 10);
	assert(dynarray.nb_cells == 0);
	assert(dynarray.byte_size == 100);
	return (0);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
//	int ret;
//	t_dynarray dynarray;
//	//secure negative arguments ----> X
//	init_dynarray(&dynarray, (uint64_t)atoi(argv[1]), (size_t)atoi(argv[2]));
//	test_init_dynarray();
//	test_free_dynarray();
//	test_pop_dynarray();
//	test_push_dynarray();
//	test_dynarray_extract();
//	test_dynarray_insert();
//	char *list;
//	char *tmp;
//	ft_memcpy(dynarray.list, "abcd", 4);
//	dynarray.nb_cells += 4;
//	printf("nb_cells of dynarray: %llu\n", dynarray.nb_cells);
//	printf("cells_size of dynarray: %zu\n", dynarray.cell_size);
//	printf("byte_size of dynarray: %llu\n", dynarray.byte_size);
//	printf("list: %s\n\n", dynarray.list);
//
//	//clear_dynarray(&dynarray, dynarray.nb_cells);
//
//	//printf("nb_cells of dynarray: %d\n", dynarray.nb_cells);
//	//printf("cells_size of dynarray: %d\n", dynarray.cell_size);
//	//printf("byte_size of dynarray: %d\n", dynarray.byte_size);
//	//printf("list: %s\n\n", dynarray.list);
//
//	//free_dynarray(&dynarray);
//	pop(&dynarray, 2, true);
//	
//	printf("nb_cells of dynarray: %llu\n", dynarray.nb_cells);
//	printf("list: %s\n\n", dynarray.list);
//
//	ret = push_dynarray(&dynarray, "3\0", 2, false);
//
//	printf("nb_cells of dynarray: %llu\n", dynarray.nb_cells);
//	printf("cells_size of dynarray: %zu\n", dynarray.cell_size);
//	printf("byte_size of dynarray: %llu\n", dynarray.byte_size);
//	printf("list: %s\n", dynarray.list);
//        t_dynarray      array;
	t_dynarray	array;
	int i = 0;
	int	*cell;

	if (init_dynarray(&array, 0, sizeof(i)))
		return (-1);
	while(i < 100)
	{
		if (push_dynarray(&array, &i, 1, false))
			return (-1);
		if (pop_dynarray(&array, 1, false))
			return (-1);
		i++;
	}
	printf("byte_size: %llu\n", array.byte_size);
	printf("nb_cells: %llu\n", array.nb_cells);
	i = 0;
	while (i < (int)array.nb_cells)
	{
		cell = dynacc(&array, (uint64_t)i);
		printf("cell %d, %d\n", i, *cell);
		i++;
	}
	return (0);
}
