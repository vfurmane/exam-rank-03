# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 08:56:16 by vfurmane          #+#    #+#              #
#    Updated: 2021/11/01 09:08:04 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= mini_paint
SRCS		= main.c
INCL		= . ..
HEAD		= $(addprefix $(word 1, $(INCL))/, mini_paint.h)
OBJS		= $(SRCS:.c=.o)
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			= rm -f

%.o:		%.c Makefile $(HEAD)
			$(CC) $(CFLAGS) -c $< $(addprefix -I, $(INCL)) -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
