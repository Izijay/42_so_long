# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 10:12:10 by mdupuis           #+#    #+#              #
#    Updated: 2021/12/09 12:04:23 by mdupuis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD = \033[1m
BLUE = \033[0;34m
CYAN = \x1b[36m
GREEN = \x1b[32m
ORANGE = \033[93m
PURPLE = \033[0;95m
RED = \033[0;91m
END = \033[0m

NAME	        =		so_long

NAME_B          =       so_long_bonus

SRCS            =       srcs/main.c\
						srcs/check_map.c\
						srcs/ft_draw.c\
						srcs/ft_error.c\
						srcs/key_manager.c\
						srcs/moves.c\
						srcs/parsing.c

SRCS_B      =       	bonus/srcs_bonus/check_map_bonus.c\
						bonus/srcs_bonus/ft_draw_bonus.c\
						bonus/srcs_bonus/ft_error_bonus.c\
						bonus/srcs_bonus/key_manager_bonus.c\
						bonus/srcs_bonus/main_bonus.c\
						bonus/srcs_bonus/moves_bonus.c\
						bonus/srcs_bonus/numbers_bonus.c\
						bonus/srcs_bonus/parsing_bonus.c\
						bonus/srcs_bonus/ennemy_moves_bonus.c

INCLUDES_DIR     =       includes/

INCLUDES_DIR_B  =       bonus/includes_bonus/

LIB_DIR         =       libft/

LIBFT           =       libft/libft.a

CC              =       gcc

OBJS            =       ${SRCS:.c=.o}

OBJS_B          =       ${SRCS_B:.c=.o}

MLX         =       minilibx/libmlx.a

MLX_DIR     =       minilibx/

RM          =       rm -rf

LFLAGS       =       -framework OpenGL -framework AppKit

FLAGS       =       -Wall -Wextra -Werror

.c.o:
					@${CC} ${FLAGS} -I${INCLUDES_DIR} -c $< -o ${<:.c=.o}
					@echo "\t\t${BOLD}${GREEN} [[ LOADED ]]${END} ${PURPLE}${<:.s=.o}${END}"

all:			${NAME}

${NAME}:		${OBJS}
						@make -C ${MLX_DIR} 2>/dev/null
						@make -C ${LIB_DIR} 2>/dev/null
						@make -C ${LIB_DIR} bonus 2>/dev/null
						@${CC} ${FLAGS} ${LFLAGS} -I${INCLUDES_DIR} -o ${NAME} ${OBJS} ${LIBFT} ${MLX}
						@echo "\t\t${BOLD}${CYAN}libft.a${END}  ${GREEN}[ OK ]${END}"
						@echo "\t\t${BOLD}${CYAN}libmlx.a${END} ${GREEN}[ OK ]${END}"
						@echo "\t\t${BOLD}${CYAN}so_long${END}  ${GREEN}[ OK ]${END}"

bonus:		${OBJS_B}
						@make -C ${MLX_DIR} 2>/dev/null
						@make -C ${LIB_DIR} 2>/dev/null
						@make -C ${LIB_DIR} bonus 2>/dev/null
						@${CC} ${FLAGS} ${LFLAGS} -I ${INCLUDES_DIR_B} -o ${NAME_B} ${OBJS_B} ${LIBFT} ${MLX}
						@echo "\t\t${BOLD}${CYAN}libft.a${END}\t\t${GREEN}[ OK ]${END}"
						@echo "\t\t${BOLD}${CYAN}libmlx.a${END}\t${GREEN}[ OK ]${END}"
						@echo "\t\t${BOLD}${CYAN}so_long_bonus${END}\t${GREEN}[ OK ]${END}"

clean:
						@make -C ${LIB_DIR} clean
						@make -C ${MLX_DIR} clean
						@${RM} ${OBJS} ${OBJS_B}
						@echo "${BOLD}${RED}\t\t *.o files deleted.${END}"

fclean:		clean
						@make -C ${LIB_DIR} fclean
						@${RM} ${NAME} ${NAME_B}
						@echo "\t\t${BOLD}${RED}Programs The libft and so_long have been deleted.${END}\n"

re:		fclean all

.PHONY:           all     clean   fclean  re
