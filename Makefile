# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pminialg <pminialg@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/02/23 09:42:19 by pminialg      #+#    #+#                  #
#    Updated: 2024/03/28 11:16:34 by pminialg      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#-------------------#
NAME = fractol

#-------------------#
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_FLAGS = -ldl -lglfw -pthread -lm
endif
ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -ldl -pthread -lm
	CFLAGS = -DOS_MAC
endif

#-------------------#
SRCS = $(wildcard src/*.c)

#-------------------#
OBJS = ${SRCS:.c=.o}

#-------------------#
CC = cc
CFLAGS += -Wall -Wextra -Werror -g -Ofast
RM = rm -rf

#-------------------#
all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@cmake -S MLX42 -B MLX42/build
	@cmake --build MLX42/build -j4
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a ./MLX42/build/libmlx42.a ${MLX_FLAGS} -o ${NAME}

# @ git submodule update --init --recursive ./MLX42
#---------#
clean:
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re