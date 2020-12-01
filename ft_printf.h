#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdint.h>
#include <stdlib.h>

typedef struct
{
	void		*list;
	void		*tmp;
	size_t		cell_size;
	uint64_t	byte_size;
	uint64_t	nb_cells;
}	t_dynarray;
#endif
