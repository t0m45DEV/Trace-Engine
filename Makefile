
OBJ_DIR = ./obj
INC_DIR = ./inc
SRC_DIR = ./src

TARGET = scape

OBJS  = $(OBJ_DIR)/main.o\
		$(OBJ_DIR)/windowDisplay.o\
		$(OBJ_DIR)/player.o\
		$(OBJ_DIR)/input.o

CC = cc

CFLAGS = -Wall -I$(INC_DIR)

LIBS = -lglut -lGLU -lGL -lm


$(TARGET) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c -MD $(CFLAGS) $< -o $@ $(LIBS)

-include $(OBJ_DIR)/*.d


.PHONY: clean
clean:
	@rm -r $(TARGET) $(OBJ_DIR)
