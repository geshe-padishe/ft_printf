/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotikcho <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 00:16:14 by nikotikch         #+#    #+#             */
/*   Updated: 2020/12/11 12:29:41 by nikotikch        ###   ########.fr       */
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
//int test_(void)
//{
//
//	return (0);
//}
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
	int ret;
	t_dynarray dynarray;
//	//secure negative arguments ----> X
	init_dynarray(&dynarray, (uint64_t)atoi(argv[1]), (size_t)atoi(argv[2]));
	test_init_dynarray();
	test_free_dynarray();
	test_pop_dynarray();
	test_push_dynarray();
	test_dynarray_extract();
	ft_memcpy(dynarray.list, "abcd", 4);
	dynarray.nb_cells += 4;
////	printf("nb_cells of dynarray: %llu\n", dynarray.nb_cells);
////	printf("cells_size of dynarray: %zu\n", dynarray.cell_size);
////	printf("byte_size of dynarray: %llu\n", dynarray.byte_size);
////	printf("list: %s\n\n", dynarray.list);
////
////	//clear_dynarray(&dynarray, dynarray.nb_cells);
////
////	//printf("nb_cells of dynarray: %d\n", dynarray.nb_cells);
////	//printf("cells_size of dynarray: %d\n", dynarray.cell_size);
////	//printf("byte_size of dynarray: %d\n", dynarray.byte_size);
////	//printf("list: %s\n\n", dynarray.list);
////
////	//free_dynarray(&dynarray);
////	pop(&dynarray, 2, true);
////	
////	printf("nb_cells of dynarray: %llu\n", dynarray.nb_cells);
////	printf("list: %s\n\n", dynarray.list);
////
	ret = push_dynarray(&dynarray, "3\0", 2, false);

	printf("nb_cells of dynarray: %llu\n", dynarray.nb_cells);
	printf("cells_size of dynarray: %zu\n", dynarray.cell_size);
	printf("byte_size of dynarray: %llu\n", dynarray.byte_size);
	printf("list: %s\n", dynarray.list);

	if (0)
		printf("-1 is true\n");
	return (0);
}
