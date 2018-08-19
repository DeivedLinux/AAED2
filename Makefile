OBJS = main.c Interface.c Hash.c Exception.c
CC = gcc
OBJ_NAME = main
COMPILER_FLAGS = -w
LINKER_FLAGS = `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
all: $(OBJS)
	$(CC) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)