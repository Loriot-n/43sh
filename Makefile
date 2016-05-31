##
## Makefile for  in /home/stanislas/PSU_2015_minishell2
##
## Made by CUENAT
## Login   <stanislas@epitech.net>
##
## Started on  Tue Mar 29 11:16:42 2016 CUENAT
## Last update Tue May 31 21:10:59 2016 Nicolas Loriot
##

NAME	=	42sh

CC	=	gcc

SRCS	=	src/main.c \
		src/fill_struct.c \
		src/parse_string.c \
		src/split.c \
		src/get_next_line.c \
		src/launch_main_shell.c \
		src/launch_shell.c \
		src/epur.c \
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
		src/export.c \
		src/build_source.c \
		src/check_input2.c \
		src/globing.c \
		src/cmd_history.c \
		src/get_input.c \
		src/raw_char.c \
		src/raw_history.c \
		src/raw_string.c \
		src/raw_utils.c \
		src/escape_char.c \
		src/extended_esc.c \
		src/input_signals.c \
		src/raw_free.c \

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I inc -W -Wall -Wextra -g3 -Wno-unused-parameter -lncurses

all:		$(NAME)

$(NAME): 	$(OBJS)
	 	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	 	rm -f $(OBJS)

fclean: 	clean
	 	rm -f $(NAME)

test: 	all clean

re:		fclean all

.PHONY:		all clean fclean re
