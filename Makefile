NAME	=	plazza

SRC_EXT	=	cpp
OBJ_EXT	=	o

UNIT	=	none


INC_PATH	=	./inc/
SRC_PATH	=	./src/
SRC_UNIT	=	./unit/

SRC_CORE	=	$(SRC_PATH)Core/
SRC_POOL	=	$(SRC_PATH)ThreadPool/
SRC_PIZZA	=	$(SRC_PATH)Pizza/
SRC_REQUEST	=	$(SRC_PATH)Request/
SRC_UTILS	=	$(SRC_PATH)Utils/
SRC_CONC	=	$(SRC_PATH)CompetitiveAccessAbstraction/

#SRC	=	$(SRC_PIZZA)Pizza.cpp \
		$(SRC_PIZZA)PizzaHandler.cpp \
		$(SRC_REQUEST)ARequest.cpp \
		$(SRC_REQUEST)Destroy.cpp \
		$(SRC_REQUEST)SendPizza.cpp \
		$(SRC_REQUEST)GetPizza.cpp \
		$(SRC_REQUEST)GetStat.cpp \
		$(SRC_REQUEST)SendStat.cpp \
		$(SRC_REQUEST)RequestHandler.cpp \
		$(SRC_UTILS)Convert.cpp

# SRC	=	$(SRC_CORE)CmdLineParse.cpp \
# 		$(SRC_UTILS)Convert.cpp \
# 		$(SRC_PIZZA)Pizza.cpp \
# 		$(SRC_UNIT)CmdLineParse.cpp

SRC	= 	$(SRC_CORE)Reception.cpp \
		$(SRC_CORE)CmdLineParse.cpp \
		$(SRC_UTILS)Convert.cpp \
		$(SRC_PIZZA)Pizza.cpp \
		$(SRC_PIZZA)PizzaHandler.cpp \
		$(SRC_CONC)UnixProcess.cpp \
		$(SRC_CONC)UnixThread.cpp \
		$(SRC_CONC)Time.cpp \
		$(SRC_CONC)NamedPipe.cpp \
		$(SRC_CONC)UnixMutex.cpp \
		$(SRC_CONC)UnixCondVar.cpp \
		$(SRC_POOL)ThreadPool.cpp \
		$(SRC_POOL)Task.cpp \
		$(SRC_CORE)Manager.cpp \
		$(SRC_CORE)Kitchen.cpp \
		$(SRC_REQUEST)Trame.cpp\
		$(SRC_CORE)Reception.cpp\
		$(SRC_UNIT)Reception.cpp

ifeq ($(UNIT), Pizza)
	SRC += $(SRC_UNIT)pizza.cpp
endif

ifeq ($(UNIT), Request)
	SRC += $(SRC_UNIT)Request.cpp
endif



OBJ	=	$(SRC:.$(SRC_EXT)=.$(OBJ_EXT))

INC	=	-I $(INC_PATH)

CC	=	g++

CPPFLAGS	+=	-Wall -W -lpthread -g3 $(INC)


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
