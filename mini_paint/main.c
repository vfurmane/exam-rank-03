/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:01:47 by vfurmane          #+#    #+#             */
/*   Updated: 2021/11/01 19:41:13 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

char	*init_map(t_config *config)
{
	char	*map;

	map = malloc((config->total_size + 1) * sizeof (*map));
	if (map == NULL)
		return (NULL);
	memset(map, config->fill_chr, config->total_size);
	for (int i = 1; i <= config->height; i++)
		map[(config->width + 1) * i - 1] = '\n';
	return (map);
}

int	draw_shapes(const t_config *config, char *map, FILE *operation_file)
{
	int			ret;
	float		distance;
	t_circle	circle;

	while ((ret = fscanf(operation_file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.chr)))
	{
		if (ret == EOF)
			break ;
		else if (ret == 0)
			return (-1);
		for (int line = 0; line < config->height; line++)
		{
			for (int col = 0; col < config->width; col++)
			{
				distance = sqrtf((col - circle.x) * (col - circle.x) + (line - circle.y) * (line - circle.y));
				if (circle.type == 'C')
				{
					if (distance <= circle.radius)
						map[(col * (config->width + 1) + line)] = circle.chr;
				}
				else if (circle.type == 'c')
				{
					if (distance == circle.radius
						|| (circle.radius > distance && circle.radius - 1 < distance))
						map[(col * (config->width + 1) + line)] = circle.chr;
				}
				else
					return (-1);
			}
		}
	}
	return (0);
}

int	draw_map(FILE* operation_file)
{
	int			ret;
	char		*map;
	t_config	config;

	ret = fscanf(operation_file, "%d %d %c\n", &config.width, &config.height,
		&config.fill_chr);
	if (ret == 0 || ret == EOF)
		return (-1);
	if (config.width <= 0 || config.width > 300
		|| config.height <= 0 || config.height > 300)
		return (-1);
	config.total_size = (config.width + 1) * config.height;
	map = init_map(&config);
	if (map == NULL)
		return (-1);
	if (draw_shapes(&config, map, operation_file) < 0)
	{
		free(map);
		return (-1);
	}
	write(1, map, config.total_size);
	free(map);
	return (0);
}

int	main(int argc, char **argv)
{
	FILE	*operation_file;

	if (argc != 2)
		return (write(1, "Error: argument\n", 16) * 0 + 1);
	operation_file = fopen(argv[1], "r");
	if (operation_file == NULL)
		return (write(1, "Error: Operation file corrupted\n", 32) * 0 + 1);
	if (draw_map(operation_file) < 0)
		return (write(1, "Error: Operation file corrupted\n", 32) * 0 + 1);
	fclose(operation_file);
	return (0);
}
