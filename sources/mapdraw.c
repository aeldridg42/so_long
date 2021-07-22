#include "../includes/so_long.h"

static void	draw1(t_game *game, int i, int i2)
{
	if (game->map.map[i][i2] == 'P')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i2 * SCALE, i * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, i2 * SCALE, i * SCALE);
		game->players.p_x = i2;
		game->players.p_y = i;
	}
	else if (game->map.map[i][i2] == '1')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.wall, i2 * SCALE, i * SCALE);
}

static void	draw2(t_game *game, int i, int i2)
{
	if (game->map.map[i][i2] == 'E')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i2 * SCALE, i * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.c_exit, i2 * SCALE, i * SCALE);
	}
	else
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i2 * SCALE, i * SCALE);
}

void	mapdraw(t_game *game)
{
	int	i;
	int	i2;

	i = -1;
	while (game->map.map[++i])
	{
		i2 = -1;
		while (game->map.map[i][++i2])
		{
			if (game->map.map[i][i2] == 'P' || game->map.map[i][i2] == '1')
				draw1(game, i, i2);
			else if (game->map.map[i][i2] == 'E' || game->map.map[i][i2] == '0')
				draw2(game, i, i2);
			else if (game->map.map[i][i2] == 'C')
			{
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
					game->images.grass, i2 * SCALE, i * SCALE);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
					game->images.coin, i2 * SCALE, i * SCALE);
			}
		}
	}
}
