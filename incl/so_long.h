/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:17:38 by adouib            #+#    #+#             */
/*   Updated: 2022/02/06 15:01:23 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define ESC_KEY 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2

# define PLAYER "./images/pumpkin.XPM"
# define EXIT_CLOSE "./images/exit_close.XPM"
# define EXIT_OPEN "./images/exit_open.XPM"
# define FLOOR "./images/floor.XPM"
# define WALL "./images/wall.XPM"
# define COLLECT "./images/beer.XPM"

# define IMG_WIDTH 48
# define IMG_HEIGHT 48
# define BUFFER_SIZE 1

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_width;
	int		img_height;

	int		map_fd;
	char	**map;
	char	*line;
	char	*backup;
	int		map_width;
	int		map_height;

	int		p_x;
	int		p_y;

	int		player;
	int		collect;
	int		exit;
}	t_game;

// get_next_line functions

char	*get_next_line(int fd);
char	*ft_strjoin(char *backup, char *file_buffer);
char	*ft_strdup(char *s);
int		search_newline(char *s, char c);
int		ft_slen(char *s);

// so long - parsing functions

void	parsing(const char *av[], t_game *game);
char	**map_read(const char *av[], t_game *game);
void	check_map_extension(const char *av[]);
void	check_rectangle(char *map[]);
void	check_walls(char *map[], t_game *game);
void	check_characters(char *map[], t_game *game);
int		map_width(char *s);
int		map_height(char *s[]);
int		search_map(char *s, char c);
char	**ft_split(char *s, char c);
int		ft_strrstr(const char *haystack, const char *needle, int n);
int		ft_strchr(char *s, char c);
int		ft_strlen(const char *s);

// so long - rendering functions

void	rendering(t_game *game);
void	draw_wall_floor(t_game *game, char c);
void	draw_player(t_game *game, int y, int x);
void	draw_collects(t_game *game);
void	draw_exit(t_game *game);
int		event_helper(int keycode, t_game *game);
void	move_helper(int keycode, t_game *game);
void	move_player(int keycode, t_game *game);
int		is_barriernext(t_game *game, char c);
int		collect_count(char *s[]);
void	print_moves(void);

// so long - quit and free functions

void	quit(t_game *game, char *s);
void	free_image(t_game *game);
int		red_cross_quit(t_game *game);
char	**free_map(char **token);

#endif
