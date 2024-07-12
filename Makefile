
OBJ_DIR = ./obj
INC_DIR = ./inc
SRC_DIR = ./src
EXP_DIR = ./exports

TARGET = Tom_3D_game_engine

EXPORT_NAME = $(EXP_DIR)/GameName

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

CC = gcc

CFLAGS = -Wall -I$(INC_DIR) -g

EXPORTFLAGS = $(CFLAGS) -no-pie

LIBS = -lglut -lGLU -lGL -lm

VALGRIND_FLAGS = --leak-check=full

MESSAGE = echo '>> $(1)'

$(TARGET) : $(OBJS)
	@$(call MESSAGE,Creating executable for $(TARGET)...)
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)
	@$(call MESSAGE,Executable for $(TARGET) created)
	@$(call MESSAGE,Have fun!)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(call MESSAGE,Creating $@...)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c -MD $(CFLAGS) $< -o $@ $(LIBS)
	@$(call MESSAGE,$@ succesfully created)

-include $(OBJ_DIR)/*.d

$(EXPORT_NAME) : $(OBJS)
	@mkdir -p $(EXP_DIR)
	@$(call MESSAGE,Creating executable for $(EXPORT_NAME)...)
	@$(CC) $(EXPORTFLAGS) $(OBJS) -o $(EXPORT_NAME) $(LIBS)
	@$(call MESSAGE,Executable for $(EXPORT_NAME) created)
	@$(call MESSAGE,Have fun!)


.PHONY: clean
clean:
	@$(call MESSAGE,Deleting previous version...)
	@rm -r $(TARGET) $(OBJ_DIR) $(EXP_DIR)
	@$(call MESSAGE,Every object file and the executable no longer exists)

play: $(TARGET)
	@$(call MESSAGE,Running $(TARGET)...)
	@./$(TARGET)

debug: $(TARGET)
	@$(call MESSAGE,Creating debug sesion for $(TARGET)...)
	@gdb ./$(TARGET)

mem_check: $(TARGET)
	@$(call MESSAGE,Creating memory check sesion for $(TARGET)...)
	@valgrind $(VALGRIND_FLAGS) ./$(TARGET)

export_lin: $(EXPORT_NAME)
	@strip $(EXPORT_NAME)
	@$(call MESSAGE,Linux executable $(EXPORT_NAME) created!)