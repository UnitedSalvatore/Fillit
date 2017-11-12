/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:34:11 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/12 08:58:20 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fillit.h"

int		main(int ac, char **av)
{
	t_tetr	*list;
	t_tetr	*temp;

	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit map.fillit", STDERR_FILENO);
		return (1);
	}
	list = ft_readfile(av[1]);
	if (ft_tetrcheck(list))
		ft_putendl_fd("error", STDERR_FILENO);
	else
		ft_putendl("success");
	temp = list;
	while (temp)
	{
		ft_putstr(temp->content);
		ft_putchar('\n');
		temp = temp->next;
	}
	ft_tetrdel(&list);
	return (0);
}
