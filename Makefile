##
## Makefile for  in /home/stanislas/PSU_2015_minishell2
##
## Made by CUENAT
## Login   <stanislas@epitech.net>
##
## Started on  Tue Mar 29 11:16:42 2016 CUENAT
## Last update Thu May 26 15:38:58 2016 Sanchez Loris
##

NAME	=	42sh

CC	=	gcc

SRCS	=	src/main.c \
		src/fill_struct.c \
		src/parse_string.c \
		src/split.c \
		src/get_next_line.c \
		src/launch_shell.c \
		src/epur_str.c \
		src/string_utils.c \
		src/check_input.c \
		src/fill_list.c \
		src/free_struct.c \
		src/execute_instruction.c \
		src/redirection.c \
		src/alias.c \
		src/alias_list.c \
		src/signal.c \
		src/42shconfig.c \
		src/choose_type_execution.c \
		src/my_getnbr.c \
		src/build_exit.c \
		src/build_echo.c \
		src/build_setenv.c \
		src/build_unsetenv.c \
		src/build_cd.c \
		src/build_env.c \
		src/env_values.c \
		src/check_options.c \
		src/join.c \

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I inc -W -Wall -Wextra -g3

all:		$(NAME)

$(NAME): 	$(OBJS)
	 	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	 	rm -f $(OBJS)

fclean: 	clean
	 	rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
