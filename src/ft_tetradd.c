/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 00:45:16 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/12 00:50:11 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_tetradd(t_tetr **start, t_tetr *new)
{
	if (alst == NULL || new == NULL)
		return ;
	new->next = *start;
	*start = new;
}
