/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:55:09 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/27 19:44:09 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void update_player(t_cub3d *game) {
    double move_speed = 0.05;
    double rot_speed = 0.03;
    if (game->keys.w)
        move_forward(game, move_speed);
    if (game->keys.s)
        move_backward(game, move_speed);
    if (game->keys.a)
        move_left(game, move_speed);
    if (game->keys.d)
        move_right(game, move_speed);
    if (game->keys.left)
        rotate_left(game, rot_speed);
    if (game->keys.right)
        rotate_right(game, rot_speed);
}