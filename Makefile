
OBJ_DIR = ./obj
INC_DIR = ./inc
SRC_DIR = ./src

TARGET = Tom_3D_game_engine

OBJS  = $(OBJ_DIR)/main.o\
		$(OBJ_DIR)/window_display.o\
		$(OBJ_DIR)/entity.o\
		$(OBJ_DIR)/player.o\
		$(OBJ_DIR)/input.o\
		$(OBJ_DIR)/map.o\
		$(OBJ_DIR)/raycaster.o\
		$(OBJ_DIR)/trigonometry.o\
		$(OBJ_DIR)/3D_render.o\
		$(OBJ_DIR)/world.o

CC = cc

CFLAGS = -Wall -I$(INC_DIR) -g

LIBS = -lglut -lGLU -lGL -lm


$(TARGET) : $(OBJS)
	@echo ':: Creating executable for $(TARGET)...'
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)
	@echo '>> Executable for $(TARGET) created'
	@echo '>> Have fun!'

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@echo ':: Creating $@...'
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c -MD $(CFLAGS) $< -o $@ $(LIBS)
	@echo '>> $@ succesfully created'

-include $(OBJ_DIR)/*.d


.PHONY: clean
clean:
	@echo ':: Deleting previous version...'
	@rm -r $(TARGET) $(OBJ_DIR)
	@echo '>> Every object file and the executable no longer exists'

play: $(TARGET)
	@echo '>> Running game...'
	@./$(TARGET)

debug: $(TARGET)
	@echo '>> Creating debug sesion for $(TARGET)'
	@gdb ./$(TARGET)
