/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:01:47 by vfurmane          #+#    #+#             */
/*   Updated: 2021/11/01 09:20:35 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

int	main(int argc, char **argv)
{
	(void)argv; /* ===== DELETE ===== */
	if (argc != 2)
		return (write(1, "Error: argument\n", 16) * 0 + 1);
	return (0);
}
