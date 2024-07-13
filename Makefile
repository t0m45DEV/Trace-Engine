# Folders
OBJ_DIR = ./obj
INC_DIR = ./inc
SRC_DIR = ./src
EXP_DIR = ./exports

# The debug executable
ENGINE = Tom_3D_game_engine
# The final game name
EXPORT_NAME = GameName

GAME = $(EXP_DIR)/$(EXPORT_NAME)

# All the objects files, remember to add one per .c file
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

# C compiler
CC = gcc

# Linker flags
CFLAGS = -Wall -I$(INC_DIR) -g

# Flags for final executable
EXPORTFLAGS = $(CFLAGS) -no-pie

# C libraries
LIBS = -lglut -lGLU -lGL -lm

# Memory leaks check flags
VALGRIND_FLAGS = --leak-check=full

# To print my shit
MESSAGE = echo '>> $(1)'


# Create debug engine executable
$(ENGINE) : $(OBJS)
	@$(call MESSAGE,Creating executable for $(ENGINE)...)
	@$(CC) $(CFLAGS) $(OBJS) -o $(ENGINE) $(LIBS)
	@$(call MESSAGE,Executable for $(ENGINE) created)
	@$(call MESSAGE,Have fun!)

# Create the objects files
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(call MESSAGE,Creating $@...)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c -MD $(CFLAGS) $< -o $@ $(LIBS)
	@$(call MESSAGE,$@ succesfully created)

-include $(OBJ_DIR)/*.d

# Export for Linux
$(GAME) : $(OBJS)
	@mkdir -p $(EXP_DIR)
	@$(call MESSAGE,Exporting $(EXPORT_NAME) for Linux...)
	@$(CC) $(EXPORTFLAGS) $(OBJS) -o $(GAME) $(LIBS)
	@strip $(GAME)
	@$(call MESSAGE,Cleaned debug info from Linux executable!)

# So Makefile won't cry if a file has this names
.PHONY: clean

# Erase all the temporal files and executables
clean:
	@$(call MESSAGE,Deleting previous version...)
	@rm -r -f $(ENGINE) $(OBJ_DIR) $(EXP_DIR)
	@$(call MESSAGE,Every object file and the executable no longer exists)

# Makes the engine and opens it
play: $(ENGINE)
	@$(call MESSAGE,Running $(ENGINE)...)
	@./$(ENGINE)

# Makes the engine and opens it with a GDB session
debug: $(ENGINE)
	@$(call MESSAGE,Creating debug sesion for $(ENGINE)...)
	@gdb ./$(ENGINE)

# Makes the engine and opens it with a Valgrind session
mem_check: $(ENGINE)
	@$(call MESSAGE,Creating memory check sesion for $(ENGINE)...)
	@valgrind $(VALGRIND_FLAGS) ./$(ENGINE)

# Exports the game for Linux
linux_export: $(GAME)
	@$(call MESSAGE,Portable Linux version for $(EXPORT_NAME) created!)
	@$(call MESSAGE,Have fun!)