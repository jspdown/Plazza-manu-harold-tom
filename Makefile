NAME	=	plazza

SRC_EXT	=	cpp
OBJ_EXT	=	o

UNIT	=	none


INC_PATH	=	./inc/
SRC_PATH	=	./src/
SRC_UNIT	=	./unit/

SRC_PIZZA	=	$(SRC_PATH)Pizza/
SRC_REQUEST	=	$(SRC_PATH)Request/
SRC_UTILS	=	$(SRC_PATH)Utils/

SRC	=	$(SRC_PIZZA)Pizza.cpp \
		$(SRC_PIZZA)PizzaHandler.cpp \
		$(SRC_REQUEST)ARequest.cpp \
		$(SRC_REQUEST)Destroy.cpp \
		$(SRC_REQUEST)SendPizza.cpp \
		$(SRC_REQUEST)GetPizza.cpp \
		$(SRC_REQUEST)GetStat.cpp \
		$(SRC_REQUEST)SendStat.cpp \
		$(SRC_REQUEST)RequestHandler.cpp \
		$(SRC_UTILS)Convert.cpp

ifeq ($(UNIT), Pizza)
	SRC += $(SRC_UNIT)pizza.cpp
endif

ifeq ($(UNIT), Request)
	SRC += $(SRC_UNIT)Request.cpp
endif



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
