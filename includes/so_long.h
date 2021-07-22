#ifndef SO_LONG_H
# define SO_LONG_H
# define SCALE 42
# define HALF 21
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define BUFFER_SIZE 1

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map {
	char		**map;
	int			lenght;
	int			linesize;
	int			collectable;
}				t_map;

typedef struct s_player {
	int			p_y;
	int			p_x;
}				t_player;

typedef struct s_count {
	int			countmoves;
	int			exitflag;
}				t_count;

typedef struct s_mlx {
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_pics {
	void		*grass;
	void		*wall;
	void		*coin;
	void		*player;
	void		*c_exit;
}				t_pics;

typedef struct s_game {
	t_map		map;
	t_player	players;
	t_count		count;
	t_mlx		mlx;
	t_pics		images;
	char		*num;
}				t_game;

int		ft_close(int keycode, t_game game);
void	ft_error(int i, t_game *game);
void	ft_free(t_game *game);
void	winning(t_game *game);
void	loosing(t_game *game);

int		game_line(t_game *game);
void	game_lenght(char *argv, t_game *game);
void	parser(char **argv, t_game *game);

int		key_hook(int keycode, t_game *game);
void	moveright(t_game *game);
void	moveleft(t_game *game);
void	moveup(t_game *game);
void	movedown(t_game *game);
void	keycode_d(t_game *game);
void	keycode_a(t_game *game);
void	keycode_w(t_game *game);
void	keycode_s(t_game *game);

void	getimage(t_game *game);

void	mapdraw(t_game *game);

int		get_next_line(int fd, char **line);
int		nl_check(char *str);
int		ft_strlen(const char *s);
int		ft_return(int charsread, char **line);
char	*strjoin_free(char *s1, char *s2);

#endif