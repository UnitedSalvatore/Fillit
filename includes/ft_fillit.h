/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:53:07 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/15 19:01:25 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <stdint.h>
# include <stdio.h>

# define FULL_BLOCK			'#'
# define EMPTY_BLOCK		'.'
# define TETRIMINO_SIZE		20
# define TETRIMINO_WIDTH	5
# define TETRIMINO_MAX		26

# define ISVALID_ELEM(c) ((c == FULL_BLOCK || c == EMPTY_BLOCK) ? 1 : 0)

/*
**	typedef struct			s_matrix
**	{
**		struct s_matrix		*up;
**		struct s_matrix		*down;
**		struct s_matrix		*left;
**		struct s_matrix		*right;
**		char				content;
**	}						t_matrix;
**
*/

typedef	struct			s_tetr
{
	uint8_t				id;
	struct s_tetr		*next;
}						t_tetr;

t_tetr					*ft_tetrnew(const uint8_t id);
void					ft_tetradd(t_tetr **start, t_tetr *new);
void					ft_tetrdel(t_tetr **start);
int						ft_tetrcheck(const char *tetrimino);
t_tetr					*ft_readfile(const char *file_name);
uint8_t					ft_get_id(const char *tetrimino);

#endif
