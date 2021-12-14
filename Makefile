# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alebross <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 18:17:21 by alebross          #+#    #+#              #
#    Updated: 2021/12/14 18:51:33 by alebross         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror #-fsanitize=thread
NAME = philo
RM = rm -rf
DIR_OBJ = other
DIR_SRC = src
DIR_INC = inc

SRCS = 	main.c \
		check_arguments.c \
		ft_error.c \
		ft_atoi.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		get_arguments.c \
		actual_time.c \
		print_status.c \
		init.c \
		launcher.c \
		check_end.c \
		ft_usleep.c \
		exit_launcher.c

OBJS = ${addprefix ${DIR_OBJ}/,${SRCS:.c=.o}}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -lpthread
all:${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME} -lpthread

${DIR_OBJ}/%.o: ${DIR_SRC}/%.c
	[ -d $(DIR_OBJ) ] || mkdir -p $(DIR_OBJ)
	${CC} $(FLAGS) -I ${DIR_INC} -c $< -o $@

clean:
	${RM} ${OBJS}
	${RM} ${DIR_OBJ}

fclean : clean
	${RM} ${NAME}
re: fclean all
