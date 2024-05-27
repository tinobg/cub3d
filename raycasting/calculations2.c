/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:42:24 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/27 21:49:42 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	calculate_wall_x(t_cub3d *game, t_ray *ray)
{
	if (ray->side == 0)
		return (game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y - \
				floor(game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y));
	else
		return (game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x - \\
				floor(game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x));
}

int	calculate_texture_x(double wall_x, t_ray *ray)
{
	int	texture_x;

	texture_x = (int)(wall_x * (double)TEX_WIDTH);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || \
			(ray->side == 1 && ray->ray_dir_y < 0))
		texture_x = TEX_WIDTH - texture_x - 1;
	return (texture_x);
}
