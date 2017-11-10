/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:34:11 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/10 15:40:24 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"
#include "unistd.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit map.fillit", STDERR_FILENO);
	}
	return (EXIT_SUCCESS);
}
