/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_all_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:20:11 by abodnar           #+#    #+#             */
/*   Updated: 2017/11/25 18:05:05 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_make_all_matrix(t_tetr *head, int s)
{
	while (head)
	{
		if (head->id >= 0 && head->id <= 2)
			head->matrix = ft_matrix_one(head, s);
		if (head->id >= 3 && head->id <= 6)
			head->matrix = ft_matrix_two(head, s);
		if (head->id >= 7 && head->id <= 10)
			head->matrix = ft_matrix_three(head, s);
		if (head->id >= 11 && head->id <= 14)
			head->matrix = ft_matrix_four(head, s);
		if (head->id >= 15 && head->id <= 18)
			head->matrix = ft_matrix_five(head, s);
		head = head->next;
	}
}
