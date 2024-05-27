/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:56:07 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/27 22:24:46 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_cub3d *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game->player.pos_x + game->player.dir_x * move_speed;
	new_pos_y = game->player.pos_y + game->player.dir_y * move_speed;
	if (is_within_bounds(game, new_pos_x, game->player.pos_y) && \
			game->map[(int)game->player.pos_y][(int)new_pos_x] == '0')
		game->player.pos_x = new_pos_x;
	if (is_within_bounds(game, game->player.pos_x, new_pos_y) && \
			game->map[(int)new_pos_y][(int)game->player.pos_x] == '0')
			game->player.pos_y = new_pos_y;
}

void	move_backward(t_cub3d *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game->player.pos_x - game->player.dir_x * move_speed;
	new_pos_y = game->player.pos_y - game->player.dir_y * move_speed;
	if (is_within_bounds(game, new_pos_x, game->player.pos_y) && \
		game->map[(int)game->player.pos_y][(int)new_pos_x] == '0')
		game->player.pos_x = new_pos_x;
	if (is_within_bounds(game, game->player.pos_x, new_pos_y) && \
		game->map[(int)new_pos_y][(int)game->player.pos_x] == '0')
		game->player.pos_y = new_pos_y;
}

void	move_left(t_cub3d *game, double move_speed)
{
	double	move_x;
	double	move_y;
	double	new_pos_x;
	double	new_pos_y;

	move_x = game->player.dir_y * move_speed;
	move_y = game->player.dir_x * move_speed;
	new_pos_x = game->player.pos_x + move_x;
	new_pos_y = game->player.pos_y + move_y;
	if (is_within_bounds(game, new_pos_x, game->player.pos_y) && \
			game->map[(int)game->player.pos_y][(int)new_pos_x] == '0')
		game->player.pos_x = new_pos_x;
	if (is_within_bounds(game, game->player.pos_x, new_pos_y) && \
			game->map[(int)new_pos_y][(int)game->player.pos_x] == '0')
		game->player.pos_y = new_pos_y;
}

void	move_right(t_cub3d *game, double move_speed)
{
	double	move_x;
	double	move_y;
	double	new_pos_x;
	double	new_pos_y;

	move_x = game->player.dir_y * move_speed;
	move_y = -game->player.dir_x * move_speed;
	new_pos_x = game->player.pos_x + move_x;
	new_pos_y = game->player.pos_y + move_y;
	if (is_within_bounds(game, new_pos_x, game->player.pos_y) && \
			game->map[(int)game->player.pos_y][(int)new_pos_x] == '0')
		game->player.pos_x = new_pos_x;
	if (is_within_bounds(game, game->player.pos_x, new_pos_y) && \
			game->map[(int)new_pos_y][(int)game->player.pos_x] == '0')
		game->player.pos_y = new_pos_y;
}
