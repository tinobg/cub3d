/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:30:14 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/31 20:01:46 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_texture_index(char *id)
{
	if (ft_strncmp(id, "NO", 2) == 0)
		return (0);
	else if (ft_strncmp(id, "SO", 2) == 0)
		return (1);
	else if (ft_strncmp(id, "WE", 2) == 0)
		return (2);
	else if (ft_strncmp(id, "EA", 2) == 0)
		return (3);
	return (-1);
}

void	parse_textures(t_cub3d *game, char *line)
{
	char	**tokens;
	int		texture_index;

	tokens = ft_split(line, ' ');
	if (!tokens || !tokens[1])
	{
		free_tokens(tokens);
		error_exit(game, "Error: Invalid texture path");
	}
	texture_index = get_texture_index(tokens[0]);
	if (texture_index == -1)
	{
		free_tokens(tokens);
		error_exit(game, "Error: Unknown texture identifier");
	}
	free_tokens(tokens);
}
