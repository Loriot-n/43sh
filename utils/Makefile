SRCS =		test.c
OBJS =  	test.o
LIBS =		-L. -lgnl
NAME =		test
CC = 		gcc
$(NAME): 	$(OBJS)
		$(CC) $(OBJS) $(LIBS) -o $(NAME)
ALL:		$(NAME)
clean:	
		rm -f $(OBJS)
fclean:		clean
		rm -f $(NAME)
