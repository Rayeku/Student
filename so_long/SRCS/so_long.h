/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:29:21 by abougrai          #+#    #+#             */
/*   Updated: 2023/12/11 11:24:25 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft_r/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char	**tab_map;
	int		x;
	int		y;
	int		xmax;
	int		ymax;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;

	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;

	void	*floor;
	void	*wall;
	int		collectmax2;
	int		collectmax;
	int		count_mov;
	void	*collect;
	void	*exit;
	void	*player;

}			t_data;

// arg_check Pre step
char		**so_long_check(char **av);
int			check_ber(char *av, char *ber);

// valid_map.c 1st step
char		**valid_map(int lines, int map, char *av);
char		**map_to_tab(int lines, int map, t_data *mlx);
void		free_tab_map(char **tab_map);
int			full_checking(char **tab_map, int lines);
int			check_char(char **tab_map);

/* void		print_new_tab(char **tab_map);
void		print_tab(char **tab_map);
*/
// check_map.c 2nd step
int			numb_of_lines(int map);
int			check_last_and_first(char **tab_map, int lines);
int			check_middle_lines(char **tab_map, int lines);
int			check_len_lines(char **tab_map, int len_line, int lines);

// check_pec.c 2nd step bis
int			check_pec(char **tab_map, int lines);
void		pec_checking(char *tab_map, int *check_p, int *check_e,
				int *check_c);
int			check_pec_errors(int *check_p, int *check_e, int *check_c);

// find_pec.c 3rd step
int			numb_of_lines_tab(char **tab_map);
int			find_pec(char **tab_map, int lines, t_data *mlx);
char		**map_cpy(char **tab_map, int lines);
void		finding_pos(char **tab_map, int *pec, int x, int y);
void		free_double_tab_map(char **map_cpy1, char **map_cpy2);

// path_finding.c 4th step
int			path_finding(char **tab_map, int *pec, int x, int y);
void		marked(char **tab_map, int x, int y);
int			move(char **tab_map, int x, int y);
int			path_finding_c(char **tab_map, t_data *mlx, int x, int y);

// so_long.c 5th step
void		so_long(t_data *mlx);
void		c_count(char **tab_map, t_data *mlx);

// find_start_end	5th step bis
int			ft_find_postion_start(t_data *mlx);
int			ft_find_postion_end(t_data *mlx);

// window.c 6th setp
void		images_init(t_data *mlx);
void		display_map(t_data *mlx);
void		display(t_data *mlx, int x, int y, void *img);
void		*window_init(t_data *mlx);
int			quit(t_data *mlx);

// moves.c 6th step bis

int			touche(int keycode, t_data *mlx);
void		down(t_data *mlx);
void		up(t_data *mlx);
void		left(t_data *mlx);
void		right(t_data *mlx);
#endif
