# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2020/03/13 07:47:51 by mperseus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	RTv1

HDR		= 	rtv1.h

SRC		= 	rtv1_main.c					\
			rtv1_read_scene_1.c 		\
			rtv1_read_scene_2.c 		\
			rtv1_read_scene_3.c 		\
			rtv1_read_scene_4.c 		\
			rtv1_read_scene_5.c 		\
			rtv1_read_scene_6.c 		\
			rtv1_read_scene_7.c	 		\
			rtv1_save_scene_1.c			\
			rtv1_save_scene_2.c			\
			rtv1_save_scene_3.c			\
			rtv1_render.c				\
			rtv1_init_buffers.c			\
			rtv1_clean_buffers.c		\
			rtv1_antialiasing.c			\
			rtv1_color_effects.c		\
			rtv1_vector.c				\
			rtv1_color.c				\
			rtv1_trace.c				\
			rtv1_intersections.c		\
			rtv1_final_processing.c		\
			rtv1_mlx_init.c				\
			rtv1_mlx_run.c				\
			rtv1_mlx_hooks.c			\
			rtv1_mlx_put_info_1.c		\
			rtv1_mlx_put_info_2.c		\
			rtv1_mlx_put_info_3.c		\
			rtv1_put_bottom_line.c		\
			rtv1_scene_init.c			\
			rtv1_mlx_control_1.c		\
			rtv1_mlx_control_2.c		\
			rtv1_control_light.c		\
			rtv1_interface_help.c		\
			rtv1_light.c				
		
OBJ		= 	$(SRC:.c=.o)

MK_FT	=	make -C libft
CL_FT	=	make clean -C libft
FCL_FT	=	make fclean -C libft

MK_MLX	=	make -C mlx
CL_MLX	=	make clean -C mlx

ADD_ERR =	-Wall -Wextra -Werror

ADD_OPT =	-Ofast

ADD_LIB =	-L ./libft	-l ft\
			-L ./mlx	-l mlx
			
ADD_FMW =	-lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MK_FT)
			$(MK_MLX)
			gcc -o $(NAME) $(OBJ) $(ADD_ERR) $(ADD_OPT) $(ADD_LIB) $(ADD_FMW)

%.o:		%.c
			gcc -I $(HDR) $< -c -o $@ $(ADD_ERR) $(ADD_OPT)

clean:
			@/bin/rm -f $(OBJ)
			$(CL_FT)
			$(CL_MLX)

fclean: 	clean
			@/bin/rm -f $(NAME)
			$(FCL_FT)

re: 		fclean all

.PHONY: 	all clean fclean re