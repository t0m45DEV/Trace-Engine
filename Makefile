
OBJ_DIR = ./obj
INC_DIR = ./inc
SRC_DIR = ./src
EXP_DIR = ./exports

ENGINE = Tom_3D_game_engine

EXPORT_NAME = GameName

GAME = $(EXP_DIR)/$(EXPORT_NAME)

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

$(ENGINE) : $(OBJS)
	@$(call MESSAGE,Creating executable for $(ENGINE)...)
	@$(CC) $(CFLAGS) $(OBJS) -o $(ENGINE) $(LIBS)
	@$(call MESSAGE,Executable for $(ENGINE) created)
	@$(call MESSAGE,Have fun!)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(call MESSAGE,Creating $@...)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c -MD $(CFLAGS) $< -o $@ $(LIBS)
	@$(call MESSAGE,$@ succesfully created)

-include $(OBJ_DIR)/*.d

$(GAME) : $(OBJS)
	@mkdir -p $(EXP_DIR)
	@$(call MESSAGE,Creating executable for $(GAME)...)
	@$(CC) $(EXPORTFLAGS) $(OBJS) -o $(GAME) $(LIBS)
	@$(call MESSAGE,Executable for $(GAME) created)
	@$(call MESSAGE,Have fun!)


.PHONY: clean
clean:
	@$(call MESSAGE,Deleting previous version...)
	@rm -r $(ENGINE) $(OBJ_DIR) $(EXP_DIR)
	@$(call MESSAGE,Every object file and the executable no longer exists)

play: $(ENGINE)
	@$(call MESSAGE,Running $(ENGINE)...)
	@./$(ENGINE)

debug: $(ENGINE)
	@$(call MESSAGE,Creating debug sesion for $(ENGINE)...)
	@gdb ./$(ENGINE)

mem_check: $(ENGINE)
	@$(call MESSAGE,Creating memory check sesion for $(ENGINE)...)
	@valgrind $(VALGRIND_FLAGS) ./$(ENGINE)

export_lin: $(GAME)
	@strip $(GAME)
	@$(call MESSAGE,Linux executable $(GAME) created!)