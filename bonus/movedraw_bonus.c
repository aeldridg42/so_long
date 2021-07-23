#include "../includes/so_long_bonus.h"

void	moveright(t_game *game)
{
	if (game->map.map[game->players.p_y][game->players.p_x + 1] == 'E')
		winning(game);
	else if (game->map.map[game->players.p_y][game->players.p_x + 1] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->players.p_x) * SCALE - HALF,
			game->players.p_y * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, (game->players.p_x + 1) * SCALE - HALF,
			game->players.p_y * SCALE);
	}
	else if (game->map.map[game->players.p_y][game->players.p_x + 1] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->players.p_x) * SCALE - HALF,
			game->players.p_y * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->players.p_x + 1) * SCALE - HALF,
			game->players.p_y * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, (game->players.p_x + 1) * SCALE - HALF,
			game->players.p_y * SCALE);
	}
	printf("Your moves - %d\n", game->count.countmoves += 1);
	game->players.color -= 1;
}

void	moveleft(t_game *game)
{
	if (game->map.map[game->players.p_y][game->players.p_x - 1] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->players.p_x) * SCALE - HALF,
			game->players.p_y * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.heroleft1,
			(game->players.p_x - 1) * SCALE - HALF, game->players.p_y * SCALE);
	}
	else if (game->map.map[game->players.p_y][game->players.p_x - 1] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->players.p_x - 1) * SCALE - HALF,
			game->players.p_y * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->players.p_x) * SCALE - HALF,
			game->players.p_y * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.heroleft1,
			(game->players.p_x - 1) * SCALE - HALF, game->players.p_y * SCALE);
	}
	printf("Your moves - %d\n", game->count.countmoves += 1);
	game->players.color -= 1;
}

void	moveup(t_game *game)
{
	if (game->map.map[game->players.p_y - 1][game->players.p_x] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, game->players.p_x * SCALE - HALF,
			game->players.p_y * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.heroup1, (game->players.p_x) * SCALE - HALF,
			(game->players.p_y - 1) * SCALE);
	}
	else if (game->map.map[game->players.p_y - 1][game->players.p_x] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, game->players.p_x * SCALE - HALF,
			(game->players.p_y - 1) * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, game->players.p_x * SCALE - HALF,
			game->players.p_y * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.heroup1, (game->players.p_x) * SCALE - HALF,
			(game->players.p_y - 1) * SCALE);
	}
	printf("Your moves - %d\n", game->count.countmoves += 1);
	game->players.color -= 1;
}

void	movedown(t_game *game)
{
	if (game->map.map[game->players.p_y + 1][game->players.p_x] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, game->players.p_x * SCALE - HALF,
			game->players.p_y * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.herodown1, (game->players.p_x) * SCALE - HALF,
			(game->players.p_y + 1) * SCALE);
	}
	else if (game->map.map[game->players.p_y + 1][game->players.p_x] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass,
			game->players.p_x * SCALE - HALF, (game->players.p_y + 1) * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass,
			game->players.p_x * SCALE - HALF, game->players.p_y * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.herodown1, (game->players.p_x) * SCALE - HALF,
			(game->players.p_y + 1) * SCALE);
	}
	printf("Your moves - %d\n", game->count.countmoves += 1);
	game->players.color -= 1;
}
