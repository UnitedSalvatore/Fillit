/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 01:49:38 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/12 09:59:47 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

static uint8_t	ft_find_l(static uint16_t mask)
{
	if (mask == 36352 || mask == 2272 || mask == 142 || \
		mask == 18176 || mask == 1136 || mask == 71)
			return (11);
	if (mask == 51328 || mask == 25664 || mask == 12832 || \
		mask == 3208 || mask == 1604 || mask == 802)
			return (12);
	if (mask == 57856 || mask == 3616 || mask == 226 || \
		mask == 28928 || mask == 1808 || mask == 113)
			return (13);
	if (mask == 17600 || mask == 8800 || mask == 4400 || \
		mask == 1100 || mask == 550 || mask == 275)
			return (14);
	if (mask == 11776 || mask == 736 || mask == 46 || \
		mask == 5888 || mask == 368 || mask == 23)
			return (21);
	if (mask == 35008 || mask == 17504 || mask == 8752 || \
		mask == 2188 || mask == 1094 || mask == 547)
			return (22);
	if (mask == 59392 || mask == 3712 || mask == 232 || \
		mask == 29696 || mask == 1856 || mask == 116)
			return (23);
	if (mask == 50240 || mask == 25120 || mask == 12560 || \
		mask == 3140 || mask == 1570 || mask == 785)
			return (24);
	return (0);
}

static uint16_t	ft_get_bitmask(const char *tetrimino)
{
	uint16_t mask;

	mask = 0;
	while (*tetrimino != '\0')
	{   
		if (ISVALID_ELEM(*tetrimino))
		{
			if (*tetrimino == FULL_BLOCK)
				mask++;
			mask = mask << 1;
		}
		tetrimino++;
	}   
}


uint8_t		ft_get_id(const char *tetrimino)
{
	uint16_t	mask;
	uint8_t		id;

	mask = ft_get_bitmask(tetrimino);
	if (id = ft_find_l(mask))
		;
	else if (id = ft_find_skew(mask))
		;
	else if (id = ft_tetrfind_other(mask))
		;
	return (id);
}
