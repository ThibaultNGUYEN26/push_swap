# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 16:59:50 by thibnguy          #+#    #+#              #
#    Updated: 2023/03/17 11:46:08 by thibnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SOURCES		=	./src
OBJECTS		=	./bin
INCLUDES	=	./includes

SRCS		=	libft/ft_strlen.c \
				libft/ft_atoi.c \
				libft/ft_isdigit.c \
				libft/ft_split.c \
				libft/ft_strcmp.c \
				libft/ft_strdup.c \
				printf/ft_printf.c \
				printf/ft_intlen.c \
				push_swap_utils/ft_check_args.c \
				push_swap_utils/ft_print_stack.c \
				sort/ft_big_sort.c \
				sort/ft_small_sort.c \
				sort/ft_sort.c \
				sort/ft_sort5.c \
				sort_utils/ft_big_sort_utils.c \
				sort_utils/ft_big_sort_utils2.c \
				sort_utils/ft_sort5_utils.c \
				stack_utils/ft_delete_end.c \
				stack_utils/ft_delete_start.c \
				stack_utils/ft_free_stack.c \
				stack_utils/ft_insert_end.c \
				stack_utils/ft_insert_start.c \
				stack_utils/ft_new_stack.c \
				stack_utils/ft_size_stack.c \
				swap_moves/ft_swap.c \
				swap_moves/ft_ss.c \
				swap_moves/ft_rotate.c \
				swap_moves/ft_rr.c \
				swap_moves/ft_rrotate.c \
				swap_moves/ft_rrr.c \
				swap_moves/ft_push.c \

OBJS		=	$(addprefix ${OBJECTS}/, ${SRCS:.c=.o})

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
CINCLUDES	=	-I ${INCLUDES}

BLACK		=	"\033[1;30m"
RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[1;35m"
BLUE		=	"\033[1;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"

${OBJECTS}/%.o: ${SOURCES}/%.c
	@mkdir -p $(dir $@)
	@echo "● Compilation de "$(BLUE)"${notdir $<}"$(EOC)"."
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}

all: ${NAME}

${NAME}: ${OBJS} ${OBJECTS}/${NAME}.o
	@echo $(GREEN)"● Compilation du ${NAME}..."$(EOC)
	@${CC} ${CFLAGS} -g -fsanitize=address ${CINCLUDES} -o ${NAME} ${OBJS} ${OBJECTS}/${NAME}.o

clean:
	@echo ${RED}"● Supression des fichiers binaires (.o)..."$(EOC)
	@rm -rf ${OBJECTS}

fclean: clean
	@echo ${RED}"● Supression des executables et librairies..."$(EOC)
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re