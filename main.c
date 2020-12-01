#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

t_dynarray	*init_dynarray(uint64_t nb_cells, size_t cell_size)
{
  t_dynarray	*dynarray;

  dynarray = (t_dynarray*)malloc(sizeof(t_dynarray));
  dynarray->list = malloc(nb_cells * cell_size);
  dynarray->tmp = malloc(nb_cells * cell_size);
  dynarray->cell_size = cell_size;
  dynarray->nb_cells = nb_cells;
  dynarray->byte_size = cell_size * nb_cells;

  return (dynarray);
}

int main(int argc, char **argv)
{
	t_dynarray	*dynarray;

	dynarray = init_dynarray((uint64_t)atoi(argv[1]), (size_t)atoi(argv[2]));
	printf("nb_cells of dynarray: %d\n", dynarray->nb_cells);
	printf("cells_size of dynarray: %d\n", dynarray->cell_size);
	printf("byte_size of dynarray: %d\n", dynarray->byte_size);
}
