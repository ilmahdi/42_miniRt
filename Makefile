# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 10:39:16 by eabdelha          #+#    #+#              #
#    Updated: 2022/06/14 16:34:34 by eabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
NAME_LIBFT = libft.a
MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

MLX_INCLUDE = /usr/local/include
INCLUDE_1 = ./includes/minirt.h
INCLUDE_2 = ./includes/elements.h
INCLUDE_3 = ./includes/defines.h

FOBJ_SRC = object_files
OBJECT_PATH = ./object_files/

LIBFT_PATH = ./libft
SRC_PATH = ./src/
PARSE_PATH = ./parsing/
DISPLAY_PATH = ./display/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3


SRC =  	minirt.c         			\
		read_map.c					\
		read_map_utils.c 			\
		check_A_C_L_elements.c		\
		check_pl_sp_cy_elements.c	\
		check_elements_utils.c		\
		print_error_msg.c			\
		parse_elements_utils.c		\
		init_variables.c			\
		vectors_opp.c				\
		vectors_opp_2d.c			\
		fill_matrix.c				\
		matrix_opp.c				\
		cogo_manipulations.c		\
		sphere_inter.c				\
		plane_inter.c    			\
		cylinder_inter.c 			\
		disks_inter.c				\
		rgb_calculations.c			\
		objects_shading.c			\
		check_shadow_ray_elements.c	\
		get_epsilon_inter.c			\

M_SRC = rendring_mandatory.c		\
		check_double_a_c_l_man.c	\
		add_specular_light.c		\
		check_element.c				\
		objects_inters.c 			\
		check_shadow_ray.c			\

B_SRC = rendring_bonus.c				\
		pthread_display_bonus.c			\
		check_double_a_c_l_bonus.c		\
		add_specular_light_bonus.c		\
		check_element_bonus.c			\
		print_error_cone_bonus.c		\
		check_cone_element_bonus.c		\
		cone_inter_bonus.c 				\
		cone_shading_bonus.c			\
		objects_inters_bonus.c 			\
		get_epsilon_bonus.c				\
		check_shadow_ray_bonus.c		\

PIXEL = get_pixel_color.c
PIXEL_OPT = get_pixel_color_optimised.c


.PHONY : all bonus clean fclean re $(NAME)

M_OBJECTS =  $(addprefix $(OBJECT_PATH), $(SRC:.c=.o))
M_OBJECTS +=  $(addprefix $(OBJECT_PATH), $(M_SRC:.c=.o))

P_OBJECTS =  $(addprefix $(OBJECT_PATH), $(PIXEL:.c=.o))
PO_OBJECTS =  $(addprefix $(OBJECT_PATH), $(PIXEL_OPT:.c=.o))

B_OBJECTS =  $(addprefix $(OBJECT_PATH), $(SRC:.c=.o))
B_OBJECTS +=  $(addprefix $(OBJECT_PATH), $(B_SRC:.c=.o))


all: $(NAME)

$(NAME): $(FOBJ_SRC) $(M_OBJECTS) $(P_OBJECTS) $(MLX_INCLUDE)
	@make -C $(LIBFT_PATH)
	@printf "linking object files...\n"
	@$(CC) $(CFLAGS) $(M_OBJECTS) $(P_OBJECTS) $(LIBFT_PATH)/$(NAME_LIBFT) $(MLX) -o $(NAME)

optim: $(FOBJ_SRC) $(M_OBJECTS) $(PO_OBJECTS) $(MLX_INCLUDE)
	@make -C $(LIBFT_PATH)
	@printf "linking object files...\n"
	@$(CC) $(CFLAGS) $(M_OBJECTS) $(PO_OBJECTS) $(LIBFT_PATH)/$(NAME_LIBFT) $(MLX) -o $(NAME)



bonus: $(FOBJ_SRC) $(B_OBJECTS) $(P_OBJECTS) $(MLX_INCLUDE)
	@make -C $(LIBFT_PATH)
	@printf "linking object files...\n"
	@$(CC) $(CFLAGS) $(B_OBJECTS) $(P_OBJECTS) $(LIBFT_PATH)/$(NAME_LIBFT) $(MLX) -o $(NAME)

boptim: $(FOBJ_SRC) $(B_OBJECTS) $(PO_OBJECTS) $(MLX_INCLUDE)
	@make -C $(LIBFT_PATH)
	@printf "linking object files...\n"
	@$(CC) $(CFLAGS) $(B_OBJECTS) $(PO_OBJECTS) $(LIBFT_PATH)/$(NAME_LIBFT) $(MLX) -o $(NAME)


$(OBJECT_PATH)%.o: $(SRC_PATH)%.c $(INCLUDE_1) $(INCLUDE_2) $(INCLUDE_3)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJECT_PATH)%.o: $(SRC_PATH)$(PARSE_PATH)%.c $(INCLUDE_1) $(INCLUDE_2) $(INCLUDE_3)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJECT_PATH)%.o: $(SRC_PATH)$(DISPLAY_PATH)%.c $(INCLUDE_1) $(INCLUDE_2) $(INCLUDE_3)
	$(CC) $(CFLAGS) -o $@ -c $<


$(FOBJ_SRC) : 
	@mkdir $@

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -rf $(FOBJ_SRC)

fclean: clean
	@make fclean -C $(LIBFT_PATH) 
	@rm -rf $(NAME)

re: fclean all
