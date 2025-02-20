/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:36:34 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/24 14:36:20 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_double(t_game *game, char *line)
{
	int	duble;

	duble = 0;
	if (ft_strncmp(line, "NO", 2) == 0 && game->paths.no_path != NULL)
		duble = 1;
	if (ft_strncmp(line, "SO", 2) == 0 && game->paths.so_path != NULL)
		duble = 1;
	if (ft_strncmp(line, "WE", 2) == 0 && game->paths.we_path != NULL)
		duble = 1;
	if (ft_strncmp(line, "EA", 2) == 0 && game->paths.ea_path != NULL)
		duble = 1;
	if (ft_strncmp(line, "F", 1) == 0 && game->paths.f_color != -1)
		duble = 1;
	if (ft_strncmp(line, "C", 1) == 0 && game->paths.c_color != -1)
		duble = 1;
	if (duble == 1)
	{
		printf("Error\nEach configuration key must be defined only once.\n");
		exit_parsing(game);
	}
	return (1);
}

int	is_digit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '\n')
			{
				tab[i][j] = '\0';
				break ;
			}
			if (tab[i][j] < '0' || tab[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	*safe_malloc(size_t bytes)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
	{
		printf("Malloc failed\n");
		free(ptr);
	}
	return (ptr);
}

int	safe_open(t_game *game, char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCan't open the file\n");
		exit_parsing(game);
	}
	return (fd);
}
