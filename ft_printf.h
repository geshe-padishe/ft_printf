/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotikcho <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:19:38 by nikotikch         #+#    #+#             */
/*   Updated: 2020/12/01 21:12:40 by nikotikch        ###   ########.fr       */
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

#endif
