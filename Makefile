NAME	=	plazza

SRC_EXT	=	cpp
OBJ_EXT	=	o


INC_PATH	=	./inc/
SRC_PATH	=	./src/

SRC_PIZZA	=	$(SRC_PATH)Pizza/

SRC	=	$(SRC_PIZZA)Pizza.cpp \
		$(SRC_PIZZA)PizzaHandler.cpp


OBJ	=	$(SRC:.$(SRC_EXT)=.$(OBJ_EXT))

INC	=	-I $(INC_PATH)

CC	=	g++

CPPFLAGS	+=	-Wall -W $(INC)


# Rules

all:	$(NAME)

%.$(OBJ_EXT): %.$(SRC_EXT)
	$(CC) -o $@ -c $< $(INC) $(CPPFLAGS)

$(NAME):	$(OBJ)
	$(CC) -o $@ $^ $(INC) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

.PHONY:	clean fclean

## END
