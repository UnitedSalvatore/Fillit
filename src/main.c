/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:34:11 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/12 06:37:42 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fillit.h"
#include "stdlib.h"

int		main(int ac, char **av)
{
	t_tetr	*list;

	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit map.fillit", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	av[1][0] = '\0';
	list = ft_tetrnew(".##.\n.##.\n....\n....\n");
	if (ft_tetrcheck(list))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	ft_tetrdel(&list);
	return (EXIT_SUCCESS);
}
