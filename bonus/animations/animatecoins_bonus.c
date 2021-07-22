#include "../../includes/so_long_bonus.h"

void	animate_coins2(t_game *game, int i, int i2)
{
	if (game->count.countanim2 == 3300)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.coins.coin4, i * SCALE - HALF, i2 * SCALE);
	}
	else if (game->count.countanim2 == 4400)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.coins.coin5, i * SCALE - HALF, i2 * SCALE);
	}
}

void	animate_coins(t_game *game, int i, int i2)
{
	if (game->count.countanim2 == 1)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.coins.coin1, i * SCALE - HALF, i2 * SCALE);
	}
	else if (game->count.countanim2 == 1100)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.coins.coin2, i * SCALE - HALF, i2 * SCALE);
	}
	else if (game->count.countanim2 == 2200)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.coins.coin3, i * SCALE - HALF, i2 * SCALE);
	}
	animate_coins2(game, i, i2);
}
