# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 14:13:30 by crenaudi          #+#    #+#              #
#    Updated: 2020/04/25 04:10:39 by padelord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgfx.a
AR = ar rc
CC = clang
RL = ranlib
RM = rm -f
CFLAGS = -Wall -Wextra
CFLAGS += -Werror
CFLAGS += -I../../includes/libgfx_includes/
CFLAGS += -I../../includes/
SMATHS	=	distance.c			\
			normalize.c			\
			product.c			\
			quaternion.c        \
			quaternion_cal.c	\
			raddeg.c			\
			rotation.c			\
			scale.c				\
			spherical_matrice.c
SRC		=	$(addprefix maths/, $(SMATHS))

SCAM	=	camera2d.c			\
			camera3d.c
SRC		+=	$(addprefix struct_cam/, $(SCAM))

SIMG	=	image.c				\
			sprite.c			\
			init.c				\
			apply.c				\
			scale.c				\
			close.c
SRC		+=	$(addprefix struct_img/, $(SIMG))

SCOLOR	=	color_hsl.c			\
			color_rgvb.c
SRC		+=	$(addprefix color/, $(SCOLOR))

STRACE	=	bresenham.c
SRC		+=	$(addprefix trace/, $(STRACE))

OBJ = $(SRC:.c=.o)

SYS        :=    $(shell uname)

ifeq ($(SYS), Darwin)
CFLAGS += -I../../includes/libgfx_includes/MacOs/
else
CFLAGS += -I../../includes/libgfx_includes/Linux/
endif

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo		"\033[0;32m [OK] \033[0m       \033[0;33m Compiling: Libgfx.a\033[0m"
	@$(AR) $(NAME) $(OBJ)
	@$(RL) $(NAME)
	@echo		"\033[0;33m [LIBGFX][SUCCESS] \033[0m"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
