#include "../../includes/so_long.h"

void	getimage(t_game *game)
{
	int	width;
	int	height;

	game->images.grass = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/grassnew.xpm", &width, &height);
	game->images.coin = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/coin/coin1.xpm", &width, &height);
	game->images.c_exit = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/exit/exit1.xpm", &width, &height);
	game->images.wall = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/bigwall.xpm", &width, &height);
	game->images.player = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/player1.xpm", &width, &height);
	if (!game->images.grass || !game->images.coin || !game->images.c_exit
		|| !game->images.wall || !game->images.player)
		ft_error(1, game);
}
