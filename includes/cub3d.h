/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskikdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:04:26 by hskikdi           #+#    #+#             */
/*   Updated: 2022/05/11 23:05:40 by hskikdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"

# define FORWARD_ZW 13
# define BACK_S 1
# define LEFT_AQ 0
# define RIGHT_D 2
# define L_ARROW 123
# define R_ARROW 124
# define RX 1000
# define RY 1000

typedef struct s_text
{
	int				texdir;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
}					t_text;

typedef struct s_ray
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			raydirx;
	double			raydiry;
	double			camerax;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			move_speed;
	double			rot_speed;
	int				x;
	int				texture;
}					t_ray;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bpp;
	int				lline;
	int				endian;
	int				forward;
	int				back;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	int				width;
	int				height;
	void			*img2;
	int				addr2;
}					t_data;

typedef struct s_info
{
	int				c;
	int				f;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*msg_error;
	int				size_line;
	int				nb_lines;
	char			**map;
	int				error;
	int				reading_map;
	char			start;
	int				dx;
	int				dy;
	t_data			text[4];
	t_data			data;
	t_ray			r;
	t_text			t;
}					t_info;

void				ft_print_struct(t_info *info);
void				get_info(char *file, t_info *info);
void				parse_extension(char *file);
void				ft_error(char *msg);
void				parse_error(char *msg, t_info *info);
void				display_error(t_info *info);
void				free_all(t_info *info);
int					tab_len(char **tab);
void				fill_texture(char **tab, t_info *info);
int					is_inset(char *s, char c);
void				ft_init(t_info **info);
void				ft_init_next(t_info *info);
int					ft_init_map(char *s, t_info *i);
int					parse_and_fill_color(char **tab, t_info *info);
int					parse_color(char *line, t_info *info);
int					tab_len(char **tab);
void				ft_push_tab(char ***map, char *line, t_info *i);
void				copy_map(char *s, t_info *i);
int					parse_line(char *s, t_info *i);
void				file_reader(char *s, t_info *i);
int					ft_empty_line(char *line);
int					check_player_pos(char **m, t_info *i);
void				ft_get_nb_lines(char **m, t_info *i);
void				ft_check_map(char **map, t_info *i);
void				replace_space_map(char **map);
void				ft_get_pos_player(t_info *info);
void				ft_extend_map(char **map, t_info *info);
void				ft_handle_key(t_info *info);
int					ft_quit_game(t_info *info, char *msg);
void				ft_start_game(t_info *info);
void				ft_rotate_right(t_info *i);
void				ft_rotate_left(t_info *i);
void				ft_handle_move(t_info *info);
void				ft_calculs_ray(t_info *info);
void				ft_color_stripe(t_info *info);
int					ft_raycasting(t_info *info);
void				ft_init_text(t_info *info);
void				ft_init_dirplayer(t_info *info);
char				**ft_splitspace(char *s);
int					handle_color(char *str, t_info *info);
#endif
