# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/31 16:35:38 by dgaitsgo          #+#    #+#              #
#    Updated: 2017/04/28 16:48:55 by dgaitsgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop 

SRC_DIR = ./src
OBJ_DIR = ./obs
INC_DIR = ./inc

SRC_FILES = \
$(SRC_DIR)/core/transform.c \
$(SRC_DIR)/core/color.c \
$(SRC_DIR)/core/model.c \
$(SRC_DIR)/core/main.c \
$(SRC_DIR)/core/window.c \
$(SRC_DIR)/core/open_gl.c \
$(SRC_DIR)/core/midi.c \
$(SRC_DIR)/core/constructors.c \
$(SRC_DIR)/core/texture.c \
$(SRC_DIR)/core/parse_mesh.c \
$(SRC_DIR)/core/parse_tga.c \
$(SRC_DIR)/core/helpers.c \
$(SRC_DIR)/core/math.c \
$(SRC_DIR)/core/render.c \
$(SRC_DIR)/core/debug_open_gl.c \
$(SRC_DIR)/core/debug.c \
$(SRC_DIR)/core/file_helpers.c \
$(SRC_DIR)/core/fetch_memory.c \
$(SRC_DIR)/core/push_face.c \
$(SRC_DIR)/core/shader.c \
$(SRC_DIR)/core/order_data.c \
$(SRC_DIR)/core/fps_mouse.c \
$(SRC_DIR)/core/camera.c \
$(SRC_DIR)/matrix/copy_matrix.c \
$(SRC_DIR)/matrix/matrix.c \
$(SRC_DIR)/matrix/inverse_rotation_matrix.c \
$(SRC_DIR)/matrix/matrix_getters.c \
$(SRC_DIR)/matrix/transformation_matrix.c \
$(SRC_DIR)/matrix/inverse_transformations.c \
$(SRC_DIR)/matrix/matrix_utility.c \
$(SRC_DIR)/matrix/rotation_matrix.c \
$(SRC_DIR)/vector/vector.c \
$(SRC_DIR)/vector/vector_basic_ops.c \
$(SRC_DIR)/vector/vector_basic_ops2.c \
$(SRC_DIR)/vector/vector_basic_ops3.c \
$(SRC_DIR)/vector/vector_constructors.c \
$(SRC_DIR)/vector/vector_min_max.c \
$(SRC_DIR)/vector/vector_scale.c \
$(SRC_DIR)/vector/vector_transformations.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

INC_FILES = \
$(INC_DIR)/scop.h \
$(INC_DIR)/libft.h \
$(INC_DIR)/get_next_line.h \
$(INC_DIR)/macros.h \
$(INC_DIR)/matrix.h \
$(INC_DIR)/texture.h \
$(INC_DIR)/flags.h \
$(INC_DIR)/transform.h \
$(INC_DIR)/time.h \
$(INC_DIR)/vector.h \
$(INC_DIR)/model.h \
$(INC_DIR)/window.h \
$(INC_DIR)/ft_math.h \
$(INC_DIR)/helpers.h \

LIB_DIR = ./lib/libft

FLAGS = #-Wall -Wextra -Werror -g

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C ./lib/libft
	gcc $(FLAGS) -o $(NAME) $(OBJ_FILES) -L$(LIB_DIR) -lft -F/Library/Frameworks -framework SDL2 -framework OpenGL -framework Foundation -framework CoreMIDI

%.o:%.c $(INC_FILES)
	gcc -c $(FLAGS) -I$(INC_DIR) $< -o $@

clean:
	make -C ./lib/libft/ clean
	rm -rf $(OBJ_FILES)

fclean: clean
	make -C ./lib/libft/ fclean
	rm -rf $(NAME)

re: fclean all
