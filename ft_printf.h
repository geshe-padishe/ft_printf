/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:28:06 by ngenadie          #+#    #+#             */
/*   Updated: 2021/03/08 16:07:01 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	conv
{
	char conversions[9] = "cspdiuxX";
	int precision;
	int fld_wdt;
	char conversion;
	bool flags[5];
	char len_modif;
}				conv;
#endif
