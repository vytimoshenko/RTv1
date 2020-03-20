# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2020/03/20 11:51:38 by mperseus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	RTv1

HDR		= 	rtv1.h

SRC		= 	$(wildcard src_start/*.c)		\
			$(wildcard src_file/*.c)		\
			$(wildcard src_trace/*.c)		\
			$(wildcard src_effect/*.c)		\
			$(wildcard src_control/*.c)		\
			$(wildcard src_interface/*.c)	\
			$(wildcard src_other/*.c)
		
OBJ		= 	$(SRC:.c=.o)

MK_FT	=	make			-C libft
CL_FT	=	make clean		-C libft
FCL_FT	=	make fclean		-C libft

MK_MLX	=	make			-C mlx
CL_MLX	=	make clean		-C mlx

MK_DIR	=	@/bin/mkdir saves screenshots

ADD_ERR =	-Wall -Wextra -Werror

ADD_OPT =	-Ofast

ADD_LIB =	-L ./libft				-l ft\
			-L ./mlx				-l mlx\
			-L ./SDL2/SDL2 			-l SDL2\
			-L ./SDL2/SDL2_image	-l SDL2_image
			
ADD_FMW =	-lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MK_FT)
			$(MK_MLX)
			gcc -o $(NAME) $(OBJ) $(ADD_ERR) $(ADD_OPT) $(ADD_LIB) $(ADD_FMW)
			$(MK_DIR)

%.o:		%.c
			gcc -I $(HDR) $< -c -o $@ $(ADD_ERR) $(ADD_OPT)

clean:
			@/bin/rm -f $(OBJ)
			$(CL_FT)
			$(CL_MLX)
			@/bin/rm -rf saves
			@/bin/rm -rf screenshots

fclean: 	clean
			@/bin/rm -f $(NAME)
			$(FCL_FT)

re: 		fclean all

.PHONY: 	all clean fclean re
