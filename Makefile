# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 14:13:30 by crenaudi          #+#    #+#              #
#    Updated: 2020/05/08 13:31:02 by padelord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
LIBFT_FOLDER = src/libft/
LIBGFX_FOLDER = src/libgfx/

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -I./includes/

SRCS = 	main.c		\
	init.c		\
	texture.c	\
	raycast.c	\
	key.c		\
	parse.c		\
	legend.c	\
	draw.c		\
	move.c		\
	error.c

LDFLAGS = -lm
LDFLAGS += -L./$(LIBGFX_FOLDER) -lgfx
LDFLAGS += -L./$(LIBFT_FOLDER) -lft
CFLAGS += -I./includes/libgfx_includes/

SYS		:=	$(shell uname)
ifeq ($(SYS), Darwin)
CFLAGS += -I./includes/libgfx_includes/MacOs -I./mlx_macos
LDFLAGS += -framework OpenGl -framework AppKit
LDFLAGS += -L./mlx_macos -lmlx
SRCS += close_mac.c
else
CFLAGS += -I./includes/libgfx_includes/Linux -I./mlx_linux
LDFLAGS += -lXext -lX11 -lbsd
LDFLAGS += -L./mlx_linux -lmlx
SRCS += close_linux.c
endif


RM = rm -f

SRC	=	$(addprefix src/, $(SRCS))

OBJ = $(SRC:.c=.o)

%.o: %.c includes/wolf.h Makefile
	@echo -n "\033[0;33m Compiling :\033[0m $@"
	@$(CC) -o $@ -c $< -I./includes/ $(CFLAGS)
	@echo "\033[0;32m [OK] \033[0m"

.PHONY: all fclean re

all: $(NAME)

ifeq ($(SYS), Darwin)
$(MLX): mlx_macos/lmlx.a
		@make -sC mlx_macos
else
$(MLX):	mlx_linux/lmlx.a
		@make -sC mlx_linux
endif

$(NAME): $(OBJ)
	@make -sC $(LIBFT_FOLDER)
	@make -sC $(LIBGFX_FOLDER)
	@echo -n "\033[0;33m Compiling :\033[0m $(NAME)"
	@$(CC) -o $(NAME) -g3 $(OBJ) $(LDFLAGS)
	@echo "\033[0;32m [OK] \033[0m\n\033[0;33m [WOLF]\033[0;32m[SUCCESS] \033[0m"

clean:
	@$(RM) $(OBJ)
	@make -sC $(LIBFT_FOLDER) clean
	@make -sC $(LIBGFX_FOLDER) clean
	@echo		"\033[0;34m [CLEAN][SUCCESS] \033[0m"

fclean: clean
	@$(RM) $(NAME)
	@make -sC $(LIBFT_FOLDER) fclean
	@make -sC $(LIBGFX_FOLDER) fclean
	@echo		"\033[0;34m [FCLEAN][SUCCESS] \033[0m"

re: fclean all
