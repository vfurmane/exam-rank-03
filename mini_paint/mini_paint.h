/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:01:18 by vfurmane          #+#    #+#             */
/*   Updated: 2021/11/01 11:28:42 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_config
{
	int			width;
	int			height;
	char		fill_chr;
	int			total_size;
}				t_config;

typedef struct s_circle
{
	char		type;
	float		x;
	float		y;
	float		radius;
	char		chr;
}				t_circle;

#endif
