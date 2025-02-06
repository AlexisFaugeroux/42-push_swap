# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 16:50:54 by afaugero          #+#    #+#              #
#    Updated: 2025/02/06 12:21:15 by afaugero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
LIBFT_DIR= libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -L ./libft -lft

SRC_MAIN = mandatory/main \

SRC = mandatory/algos/push_swap \
	  mandatory/algos/sort_three \
	  mandatory/algos/helpers/rotations \
	  mandatory/instructions/push \
	  mandatory/instructions/rev_rotate \
	  mandatory/instructions/rotate \
	  mandatory/instructions/swap \
	  mandatory/params/set_params \
	  mandatory/params/update_params \
	  mandatory/params/helpers/find_cheapest \
	  mandatory/params/helpers/find_lowest \
	  mandatory/params/helpers/find_max_val \
	  mandatory/params/helpers/find_median \
	  mandatory/params/helpers/find_target \
	  mandatory/parse/parse \
	  mandatory/parse/helpers/every \
	  mandatory/parse/helpers/foreach \
	  mandatory/parse/helpers/is_sort \
	  mandatory/parse/helpers/join_args \
	  mandatory/stack/init_stack \
	  mandatory/stack/helpers/stack_add_back \
	  mandatory/stack/helpers/stack_at \
	  mandatory/stack/helpers/stack_clear \
	  mandatory/stack/helpers/stack_find \
	  mandatory/stack/helpers/stack_is_sorted \
	  mandatory/stack/helpers/stack_last \
	  mandatory/stack/helpers/stack_new \
	  mandatory/stack/helpers/stack_size \
	  mandatory/stack/helpers/stack_sort \
	  mandatory/utils/free_matrix \
	  mandatory/utils/matrix_errors \

SRC_BONUS = bonus/checker_bonus \
			bonus/instructions/push_bonus \
			bonus/instructions/rev_rotate_bonus \
			bonus/instructions/rotate_bonus \
			bonus/instructions/swap_bonus \
			bonus/parse/parse_bonus \

SRCS_MAIN = $(addsuffix .c, ${SRC_MAIN})
SRCS = $(addsuffix .c, ${SRC})
SRCS_BONUS = $(addsuffix .c, ${SRC_BONUS})

OBJECTS_MAIN = $(SRCS_MAIN:.c=.o)
OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)


all: ${NAME}

%.o: %.c
	${CC} $(CFLAGS) -c $< -o $@

checker/%.o: checker/%.c
	${CC} $(CFLAGS) -c $< -o $@

$(NAME): ${OBJECTS_MAIN} $(OBJECTS)
	make -C ${LIBFT_DIR} all
	${CC} ${CFLAGS} $(OBJECTS_MAIN) ${OBJECTS} -o ${NAME} ${INCLUDES}

bonus: checker

checker: ${OBJECTS} ${OBJECTS_BONUS}
	make -C ${LIBFT_DIR} all
	${CC} ${CFLAGS} ${OBJECTS} ${OBJECTS_BONUS} -o $(BONUS) ${INCLUDES}

clean:
	make -C ${LIBFT_DIR} clean
	rm -f $(OBJECTS_MAIN) $(OBJECTS) ${OBJECTS_BONUS}

fclean: clean
	rm -f ${LIBFT_DIR}/libft.a
	rm -f $(NAME) $(BONUS)

re:	fclean all

.PHONY: all bonus clean fclean re
