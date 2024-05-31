/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:15:48 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/31 13:27:42 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_player_position(t_cub3d *game, int x, int y)
{
	game->player.pos_x = x + 0.5;
	game->player.pos_y = y + 0.5;
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->map[y][x] = '0';
}

static void	init_player_position(t_cub3d *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (y >= 0 && y < game->map_height && x >= 0 && x < \
				(int)ft_strlen(game->map[y]) && game->map[y][x] == 'N')
			{
				set_player_position(game, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	parse_line(t_cub3d *game, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		parse_textures(game, line);
	else if (line[0] == 'S' && line[1] == 'O')
		parse_textures(game, line);
	else if (line[0] == 'W' && line[1] == 'E')
		parse_textures(game, line);
	else if (line[0] == 'E' && line[1] == 'A')
		parse_textures(game, line);
	else if (line[0] == 'F')
		parse_color(&game->floor_color, line);
	else if (line[0] == 'C')
		parse_color(&game->ceiling_color, line);
	else
		parse_map(game, line);
}

void	parse_file(t_cub3d *game, const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Error: Error opening file");
	while (get_next_line(fd, &line) > 0)
	{
		parse_line(game, line);
		free(line);
	}
	close(fd);
	init_player_position(game);
}
