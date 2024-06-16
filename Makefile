
OBJ_DIR = ./obj
INC_DIR = ./inc
SRC_DIR = ./src

TARGET = scape

OBJS  = $(OBJ_DIR)/main.o\
		$(OBJ_DIR)/window_display.o\
		$(OBJ_DIR)/player.o\
		$(OBJ_DIR)/input.o\
		$(OBJ_DIR)/map.o\
		$(OBJ_DIR)/raycaster.o\
		$(OBJ_DIR)/trigonometry.o\
		$(OBJ_DIR)/3D_render.o

CC = cc

CFLAGS = -Wall -I$(INC_DIR) -g

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
