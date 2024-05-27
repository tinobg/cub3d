/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:51:13 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/27 21:39:56 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (2);
		else
			return (3);
	}
}
