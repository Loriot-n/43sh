##
## Makefile for  in /home/stanislas/PSU_2015_minishell2
## 
## Made by CUENAT
## Login   <stanislas@epitech.net>
## 
## Started on  Tue Mar 29 11:16:42 2016 CUENAT
## Last update Fri Apr  8 13:20:22 2016 CUENAT
##

NAME	=	mysh

CC	=	gcc

SRCS	=	utils/utils_1.c \
		utils/get_next_line.c \
		utils/my_getnbr.c \
		utils/utils_2.c \
		utils/utils_3.c \
		src/main.c \
		src/env_function.c \
		src/list_function.c \
		src/exec_function.c \
		src/check_input.c \
		src/exec_and_redirect.c \
		src/exec_build_in.c \
		src/signal.c \
		src/exec_cd.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I include -W -Wall -Wextra -g3

all:		$(NAME)

$(NAME): 	$(OBJS)
	 	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	 	rm -f $(OBJS)

fclean: 	clean
	 	rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
