# Folders
OBJ_DIR := obj
INC_DIR := inc
SRC_DIR := src
EXP_DIR := bin
DAT_DIR := data
TST_DIR := tests
THIRDPARTY_DIR := thirdparty

OBJ_EXP_DIR := obj_exp

# The debug executable
ENGINE_NAME := Tom_3D_game_engine
# The final game name
EXPORT_NAME := GameName

GAME   := $(EXP_DIR)/$(EXPORT_NAME)
ENGINE := $(EXP_DIR)/$(ENGINE_NAME)

# To get the C files
SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')

# To get all the objects files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# To get all the objects files for the final export
OBJ_EXP_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_EXP_DIR)/%.o, $(SRC_FILES))

IMG_PARSER_DIR := imageParser
IMG_PARSER_C   := $(IMG_PARSER_DIR)/imageParser.c
IMG_PARSER     := $(EXP_DIR)/imageParser.out

TEXTURES_STRUCT_DIR  := ./textures/structures.png
TEXTURES_STRUCT_FILE := $(DAT_DIR)/structures.ted
TEXTURES_INFO_FILE   := $(INC_DIR)/textures_info.h

RUN_IMG_PARSER := ./$(IMG_PARSER) $(TEXTURES_STRUCT_DIR) $(TEXTURES_STRUCT_FILE) $(TEXTURES_INFO_FILE)

# C compiler
CC = gcc

# SDL2 location
SDL2_DIR := $(THIRDPARTY_DIR)/SDL2/include

# Linker flags
CFLAGS = -Wall -Wextra -O3 -I$(INC_DIR) -I$(THIRDPARTY_DIR) -I$(SDL2_DIR) -g 

# Flags for final executable
EXPORTFLAGS = -DGAME_EXPORT $(CFLAGS) -no-pie

# C libraries
LIBS = $(THIRDPARTY_DIR)/SDL2/build/.libs/libSDL2.a -lGL -lm

# Memory leaks check flags
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all

# The tests files
TST_C := testing.c

TST_FILES := ./$(TST_DIR)/$(TST_C)\
				./$(OBJ_DIR)/trigonometry.o\
				./$(OBJ_DIR)/log.o

TST_FLAGS := $(CFLAGS)
TST_LIBS := $(LIBS)

TST_BIN := ./$(TST_DIR)/test

# To print my shit
RED     := 1
GREEN   := 2
YELLOW  := 3
BLUE    := 4
MAGENTA := 5
CYAN    := 6
WHITE   := 7

DEFAULT_COL := $(WHITE)
INFO_COL    := $(CYAN)
ERROR_COL   := $(RED)
SUCCESS_COL := $(GREEN)

MESSAGE = tput setaf $1;echo '>> $2';tput setaf $(DEFAULT_COL);


# Create debug engine executable
$(ENGINE) : parser setup_sdl2 $(OBJ_FILES)
	@$(call MESSAGE,$(INFO_COL),Creating executable for $(ENGINE_NAME)...)
	@mkdir -p $(EXP_DIR)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(ENGINE) $(LIBS)
	@$(call MESSAGE,$(SUCCESS_COL),Executable for $(ENGINE) created)
	@$(call MESSAGE,$(INFO_COL),Have fun!)

# Create the objects files
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(call MESSAGE,$(INFO_COL),Creating $@...)
	@mkdir -p $(dir $@)
	@$(CC) -c -MD $(CFLAGS) $< -o $@
	@$(call MESSAGE,$(SUCCESS_COL),$@ succesfully created)

-include ./$(OBJ_DIR)/*.d

$(IMG_PARSER) : ./$(IMG_PARSER_C)
	@$(call MESSAGE,$(INFO_COL),Compiling image parser...)
	@mkdir -p $(EXP_DIR) $(DAT_DIR)
	@$(CC) ./$(IMG_PARSER_C) -o $(IMG_PARSER) -I$(THIRDPARTY_DIR) -lm
	@$(call MESSAGE,$(SUCCESS_COL),Image parser compiled!)

# Export for Linux
$(GAME) : $(ENGINE) $(OBJ_EXP_FILES)
	@mkdir -p ./$(EXP_DIR)
	@$(call MESSAGE,$(INFO_COL),Exporting $(EXPORT_NAME) for Linux...)
	@$(CC) $(EXPORTFLAGS) $(OBJ_EXP_FILES) -o $(GAME) $(LIBS)
	@strip $(GAME)
	@$(call MESSAGE,$(SUCCESS_COL),Cleaned debug info from Linux executable!)

# Create the objects files for export
$(OBJ_EXP_DIR)/%.o : $(SRC_DIR)/%.c
	@$(call MESSAGE,$(INFO_COL),Creating $@ for export...)
	@mkdir -p $(dir $@)
	@$(CC) -c -MD $(EXPORTFLAGS) $< -o $@
	@$(call MESSAGE,$(SUCCESS_COL),$@ succesfully created)

-include ./$(OBJ_EXP_DIR)/*.d

# So Makefile won't cry if a file has this names
.PHONY: all clean play debug mem_check export test parser

all: $(ENGINE) $(GAME)

# Erase all the temporal files and executables
clean:
	@$(call MESSAGE,$(INFO_COL),Deleting previous version...)
	@rm -fr $(ENGINE) ./$(OBJ_DIR) ./$(EXP_DIR) ./$(TST_BIN) ./$(IMG_PARSER) ./$(OBJ_EXP_DIR)
	@$(call MESSAGE,$(INFO_COL),Every object file and the executable no longer exists)

# Makes the engine and opens it
play: $(ENGINE)
	@$(call MESSAGE,$(INFO_COL),Running $(ENGINE)...)
	@./$(ENGINE)

# Makes the engine and opens it with a GDB session
debug: $(ENGINE)
	@$(call MESSAGE,$(INFO_COL),Creating debug sesion for $(ENGINE)...)
	@gdb ./$(ENGINE)

# Makes the engine and opens it with a Valgrind session
mem_check: $(ENGINE)
	@$(call MESSAGE,$(INFO_COL),Creating memory check sesion for $(ENGINE)...)
	@valgrind $(VALGRIND_FLAGS) ./$(ENGINE)

# Exports the game for Linux
export: $(GAME)
	@$(call MESSAGE,$(SUCCESS_COL),Portable Linux version for $(EXPORT_NAME) created!)
	@$(call MESSAGE,$(INFO_COL),Have fun!)

# Run the tests
test: $(ENGINE)
	@$(call MESSAGE,$(CYAN),Compiling the tests...)
	@$(CC) $(TST_FILES) $(TST_FLAGS) $(TST_LIBS) -o $(TST_BIN)
	@$(call MESSAGE,$(GREEN),Test compiled!)
	@$(call MESSAGE,$(CYAN),Running tests...)
	@./$(TST_BIN)
	@rm $(TST_BIN)
	@$(call MESSAGE,$(GREEN),Tests finished running!)

parser: ./$(IMG_PARSER)
	@$(call MESSAGE,$(INFO_COL),Parsing images...)
	@$(RUN_IMG_PARSER)
	@rm ./$(IMG_PARSER)
	@$(call MESSAGE,$(SUCCESS_COL),All images parsed!)

setup_sdl2:
	@$(call MESSAGE,$(INFO_COL),Building SDL2 from source... (this may take a while))
	@cd $(THIRDPARTY_DIR)/SDL2 && ./configure --disable-shared --enable-static > /dev/null && make > /dev/null
	@$(call MESSAGE,$(INFO_COL),SDL2 built succesfully!)
