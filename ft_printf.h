/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotikcho <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:19:38 by nikotikch         #+#    #+#             */
/*   Updated: 2020/12/02 23:46:00 by nikotikch        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	void		*list;
	void		*tmp;
	size_t		cell_size;
	uint64_t	byte_size;
	uint64_t	nb_cells;
}	t_dynarray;

int	init_dynarray(t_dynarray *dynarray, uint64_t nb_cells, size_t cell_size);
void clear_dynarray(t_dynarray *dynarray, uint64_t nb_cells);
void free_dynarray(t_dynarray *dynarray);
int push_dynarray(t_dynarray *dynarray, void *new_cells, uint64_t new_byte_size, int direction);
void my_memcpy(void *ptr, void *ptr2, uint64_t n);

#endif
