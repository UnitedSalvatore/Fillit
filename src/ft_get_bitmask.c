/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bitmask.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:38:08 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/15 18:50:35 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint16_t	ft_get_bitmask(const char *tetrimino)
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
