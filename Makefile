##
## Makefile for  in /home/stanislas/PSU_2015_minishell2
##
## Made by CUENAT
## Login   <stanislas@epitech.net>
##
## Started on  Tue Mar 29 11:16:42 2016 CUENAT
## Last update Tue May 24 15:33:52 2016 CUENAT
##

NAME	=	42sh

CC	=	gcc

SRCS	=	src/main.c \
		src/fill_struct.c \
		src/parse_string.c \
		src/my_str_to_wordtab.c \
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
