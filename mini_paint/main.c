/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:01:47 by vfurmane          #+#    #+#             */
/*   Updated: 2021/11/01 09:28:22 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

int	main(int argc, char **argv)
{
	FILE	*operation_file;

	if (argc != 2)
		return (write(1, "Error: argument\n", 16) * 0 + 1);
	operation_file = fopen(argv[1], "r");
	if (operation_file == NULL)
		return (write(1, "Error: Operation file corrupted\n", 32) * 0 + 1);
	fclose(operation_file);
	return (0);
}
