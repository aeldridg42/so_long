#include "../includes/so_long_bonus.h"

static void	gameinit(t_game *game)
{
	getimage(game);
	game->count.countmoves = 0;
	game->count.countanim = 0;
	game->count.countanim2 = 0;
	game->count.exitflag = 0;
	game->count.checkflag = 0;
	game->count.counthero = 0;
	game->players.heroflag = 2;
	game->mlx.mlx = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlx,
			game->map.linesize * SCALE - SCALE,
			(game->map.lenght - 1) * SCALE - HALF,
			"it took \"So long\" to understand how mlx works");
}

static void	checkargv(char **argv, t_game *game)
{
	int		i;
	int		fd;
	char	*buff;

	i = ft_strlen(argv[1]);
	if (i < 5)
		ft_error(6, game);
	if (argv[1][i - 4] != '.' || argv[1][i - 3] != 'b'
		|| argv[1][i - 2] != 'e' || argv[1][i - 1] != 'r')
		ft_error(6, game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(3, game);
	if (read(fd, &buff, 1) == -1)
		ft_error(3, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error(4, &game);
	checkargv(argv, &game);
	game.map.collectable = 0;
	parser(argv, &game);
	gameinit(&game);
	mapdraw(&game);
	mlx_string_put(game.mlx.mlx, game.mlx.win, 3, 3, 0xFFFFFF, "0");
	mlx_string_put(game.mlx.mlx, game.mlx.win, 3, 17, 0xFFFFFF, "moves");
	mlx_hook(game.mlx.win, 2, (1L << 0), key_hook, &game);
	mlx_hook(game.mlx.win, 17, 0, ft_close, &game);
	mlx_loop_hook(game.mlx.mlx, render_next_frame, &game);
	mlx_loop(game.mlx.mlx);
}
