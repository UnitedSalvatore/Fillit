/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:53:07 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/20 04:32:43 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <stdint.h>

# define FULL_BLOCK			'#'
# define EMPTY_BLOCK		'.'

# define ISVALID_ELEM(c) ((c == FULL_BLOCK || c == EMPTY_BLOCK) ? 1 : 0)

typedef	struct			s_tetr
{
	uint8_t				id;
	char				name;
	char				**matrix;
	struct s_tetr		*next;
}						t_tetr;

t_tetr					*ft_tetrnew(const uint8_t id);
void					ft_tetradd(t_tetr **start, t_tetr *new);
void					ft_tetrdel(t_tetr **start);
t_tetr					*ft_readfile(const char *file_name);
uint8_t					ft_get_id(const char *tetrimino);

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int						ft_min_square_size(t_tetr *head, int *fig_nb);
void					ft_make_all_matrix(t_tetr *head, int s);
int						ft_bigmatrix_size(int s, t_tetr *head);
char					**ft_make_bigmatrix(int size, t_tetr *head);
int						ft_do_stupid_things(char **matrix);
void					ft_clear_rows(char **matrix, int row);
void					ft_print_result(char **matrix, int s);

char					**ft_matrix_one(t_tetr *head, int s);
char					*ft_fillmatrix_i_vert(int s, int row, char name);
char					*ft_fillmatrix_i_hor(int s, int row, char name);
char					*ft_fillmatrix_sq(int s, int row, char name);
char					**ft_matrix_two(t_tetr *head, int s);
char					*ft_fillmatrix_z_hor(int s, int row, char name);
char					*ft_fillmatrix_z_vert(int s, int row, char name);
char					*ft_fillmatrix_s_hor(int s, int row, char name);
char					*ft_fillmatrix_s_vert(int s, int row, char name);
char					**ft_matrix_three(t_tetr *head, int s);
char					*ft_fillmatrix_l_vert(int s, int row, char name);
char					*ft_fillmatrix_l_vert_rev(int s, int row, char name);
char					*ft_fillmatrix_l_hor(int s, int row, char name);
char					*ft_fillmatrix_l_hor_rev(int s, int row, char name);
char					**ft_matrix_four(t_tetr *head, int s);
char					*ft_fillmatrix_j_vert(int s, int row, char name);
char					*ft_fillmatrix_j_vert_rev(int s, int row, char name);
char					*ft_fillmatrix_j_hor(int s, int row, char name);
char					*ft_fillmatrix_j_hor_rev(int s, int row, char name);
char					**ft_matrix_five(t_tetr *head, int s);
char					*ft_fillmatrix_t_hor(int s, int row, char name);
char					*ft_fillmatrix_t_hor_rev(int s, int row, char name);
char					*ft_fillmatrix_t_vert(int s, int row, char name);
char					*ft_fillmatrix_t_vert_rev(int s, int row, char name);

#endif
