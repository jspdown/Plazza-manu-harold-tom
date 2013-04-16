NAME	=	plazza

SRC_EXT	=	cpp
OBJ_EXT	=	o


INC_PATH	=	./inc/
SRC_PATH	=	./src/

SRC	=	


OBJ	=	$(SRC:.$(SRC_EXT)=.$(OBJ_EXT))

INC	=	-I $(INC_PATH)

CC	=	g++

CPPFLAGS	+=	-Wall -W $(INC) -g -ldl


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
