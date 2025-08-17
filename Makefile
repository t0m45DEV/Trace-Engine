# Folders
ENGINE_DIR := engine
APP_DIR := application

ENG_INC_DIR := $(ENGINE_DIR)/inc
ENG_SRC_DIR := $(ENGINE_DIR)/src
ENG_DAT_DIR := $(ENGINE_DIR)/data
ENG_TST_DIR := $(ENGINE_DIR)/tests
THIRDPARTY_DIR := $(ENGINE_DIR)/thirdparty

APP_INC_DIR := $(APP_DIR)/inc
APP_SRC_DIR := $(APP_DIR)/src

SRC_DIRS := $(ENG_SRC_DIR) $(APP_SRC_DIR)

EXP_DIR := bin
OBJ_DIR := obj

OBJ_EXP_DIR := obj_exp

# The debug executable
ENGINE_NAME := Tom_3D_game_engine
# The final game name
EXPORT_NAME := GameName

GAME   := $(EXP_DIR)/$(EXPORT_NAME)
ENGINE := $(EXP_DIR)/$(ENGINE_NAME)

# To get the C files
ENG_SRC_FILES := $(shell find $(ENG_SRC_DIR) -type f -name '*.c')
APP_SRC_FILES := $(shell find $(APP_SRC_DIR) -type f -name '*.c')

# To get all the objects files
OBJ_FILES := $(patsubst $(ENG_SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(ENG_SRC_FILES)) \
			 $(patsubst $(APP_SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(APP_SRC_FILES))

# To get all the objects files for the final export
OBJ_EXP_FILES := $(patsubst $(ENG_SRC_DIR)/%.c, $(OBJ_EXP_DIR)/%.o, $(ENG_SRC_FILES)) \
				 $(patsubst $(APP_SRC_DIR)/%.c, $(OBJ_EXP_DIR)/%.o, $(APP_SRC_FILES))

IMG_PARSER_DIR := $(ENGINE_DIR)/imageParser
IMG_PARSER_C   := $(IMG_PARSER_DIR)/imageParser.c
IMG_PARSER     := $(EXP_DIR)/imageParser.out

TEXTURES_STRUCT_DIR  := ./textures/structures.png
TEXTURES_STRUCT_FILE := $(ENG_DAT_DIR)/structures.ted
TEXTURES_INFO_FILE   := $(ENG_INC_DIR)/textures_info.h

RUN_IMG_PARSER := ./$(IMG_PARSER) $(TEXTURES_STRUCT_DIR) $(TEXTURES_STRUCT_FILE) $(TEXTURES_INFO_FILE)

# C compiler
CC = gcc

# Glad location
GLAD_INC := $(THIRDPARTY_DIR)/glad/include
GLAD_SRC := $(THIRDPARTY_DIR)/glad/src/glad.c

GLAD_OBJ := $(OBJ_DIR)/glad.o
GLAD_EXP_OBJ := $(OBJ_EXP_DIR)/glad.o

OBJ_FILES += $(GLAD_OBJ)
OBJ_EXP_FILES += $(GLAD_EXP_OBJ)

# SDL2 location
SDL2_DIR := $(THIRDPARTY_DIR)/SDL2/include

SDL2_BUILD_DIR := .build/sdl2
SDL2_STATIC := $(SDL2_BUILD_DIR)/build/.libs/libSDL2.a

# Nuklear files
NK_INC_DIR := $(THIRDPARTY_DIR)/Nuklear
NK_SDL2_INC_DIR := $(NK_INC_DIR)/demo/sdl_opengl2

# Linker flags
CFLAGS = -Wall -Wextra -O3 -g \
	-I$(ENG_INC_DIR) -I$(APP_INC_DIR) \
	-I$(THIRDPARTY_DIR) -I$(GLAD_INC) -I$(SDL2_DIR) -I$(NK_INC_DIR) -I$(NK_SDL2_INC_DIR) 

# Flags for final executable
EXPORTFLAGS = -DGAME_EXPORT $(CFLAGS) -no-pie

# C libraries
LIBS = $(SDL2_STATIC) -lGL -lm

# Memory leaks check flags
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all

# The tests files
TST_C := testing.c

TST_FILES := ./$(ENG_TST_DIR)/$(TST_C) \
				./$(OBJ_DIR)/trigonometry.o \
				./$(OBJ_DIR)/log.o

TST_FLAGS := $(CFLAGS)
TST_LIBS := $(LIBS)

TST_BIN := ./$(ENG_TST_DIR)/test

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
$(OBJ_DIR)/%.o : $(ENG_SRC_DIR)/%.c
	@$(call MESSAGE,$(INFO_COL),Creating $@...)
	@mkdir -p $(dir $@)
	@$(CC) -c -MD $(CFLAGS) $< -o $@
	@$(call MESSAGE,$(SUCCESS_COL),$@ succesfully created)

# Create the objects files
$(OBJ_DIR)/%.o : $(APP_SRC_DIR)/%.c
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

$(GLAD_OBJ) $(GLAD_EXP_OBJ) : $(GLAD_SRC)
	@$(call MESSAGE,$(INFO_COL),Compiling Glad...)
	@mkdir -p $(dir $@)
	@$(CC) -c -MD $(CFLAGS) $< -o $@
	@$(call MESSAGE,$(SUCCESS_COL),Glad compiled successfully!)

-include $(OBJ_DIR)/*.d $(OBJ_EXP_DIR)/*.d


# So Makefile won't cry if a file has this names
.PHONY: help all clean play debug mem_check export test parser

## ------------------------------------------------------
##  Welcome to the Trace Engine, or Tom's Raycaster in C
## ------------------------------------------------------
## 
##  This is a fake 3D game engine using the raycasting
##  technique made in C, feel free to go through the
##  files and see how everything works!
## 
## ------------------------------------------------------
## 
##  Written by t0m45DEV
##  Version v0.prealpha (pre everything, to be honest)
## 
##  For more information you can check the github repo
##  here:
##    https://github.com/t0m45DEV/Trace-Engine?tab=readme-ov-file
## 
##  Please report any bugs or error to the author
## 
## ------------------------------------------------------
## 
##  Here is the list for all the makefile rules:
## 

help: ## Show this help
	@egrep -h '##\s' $(MAKEFILE_LIST) | awk 'BEGIN {FS = "^## "}; $$1 == "" {printf "%s\n", $$2}'
	@egrep -h '\s##\s' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "  %-12s - %s\n\n", $$1, $$2}'

all: $(ENGINE) $(GAME) ## Compiles the engine version and the export version

# Erase all the temporal files and executables
clean: ## Deletes all the object files, the executables, the tests related files, and all that
	@$(call MESSAGE,$(INFO_COL),Deleting previous version...)
	@rm -fr $(ENGINE) ./$(OBJ_DIR) ./$(EXP_DIR) ./$(TST_BIN) ./$(IMG_PARSER) ./$(OBJ_EXP_DIR)
	@$(call MESSAGE,$(INFO_COL),Every object file and the executable no longer exists)

# Makes the engine and opens it
play: $(ENGINE) ## Compiles the game and then opens it
	@$(call MESSAGE,$(INFO_COL),Running $(ENGINE)...)
	@./$(ENGINE)

# Makes the engine and opens it with a GDB session
debug: $(ENGINE) ## Compiles the game, and then starts a GDB session with the executable
	@$(call MESSAGE,$(INFO_COL),Creating debug sesion for $(ENGINE)...)
	@gdb ./$(ENGINE)

# Makes the engine and opens it with a Valgrind session
mem_check: $(ENGINE) ## Compiles the game, and then starts a Valgrind session with the executable
	@$(call MESSAGE,$(INFO_COL),Creating memory check sesion for $(ENGINE)...)
	@valgrind $(VALGRIND_FLAGS) ./$(ENGINE)

# Exports the game for Linux
export: $(GAME) ## Compiles a final version, without debuging symbols and ready to publish
	@$(call MESSAGE,$(SUCCESS_COL),Portable Linux version for $(EXPORT_NAME) created!)
	@$(call MESSAGE,$(INFO_COL),Have fun!)

# Run the tests
test: $(ENGINE) ## Compiles the auto tests and then run them
	@$(call MESSAGE,$(CYAN),Compiling the tests...)
	@$(CC) $(TST_FILES) $(TST_FLAGS) $(TST_LIBS) -o $(TST_BIN)
	@$(call MESSAGE,$(GREEN),Test compiled!)
	@$(call MESSAGE,$(CYAN),Running tests...)
	@./$(TST_BIN)
	@rm $(TST_BIN)
	@$(call MESSAGE,$(GREEN),Tests finished running!)

parser: ./$(IMG_PARSER) ## Compiles the image parser and then executes it
	@$(call MESSAGE,$(INFO_COL),Parsing images...)
	@$(RUN_IMG_PARSER)
	@rm ./$(IMG_PARSER)
	@$(call MESSAGE,$(SUCCESS_COL),All images parsed!)

setup_sdl2: $(SDL2_STATIC) ## Compiles the SDL2 library as static (only make this the first time)

$(SDL2_STATIC):
	@$(call MESSAGE,$(INFO_COL),Building SDL2 from source... (this may take a while))
	@mkdir -p $(SDL2_BUILD_DIR)
	@cd $(SDL2_BUILD_DIR) && ../../$(THIRDPARTY_DIR)/SDL2/configure --disable-shared --enable-static prefix=$(abspath $(SDL2_BUILD_DIR)) > /dev/null
	@$(MAKE) -C $(SDL2_BUILD_DIR) > /dev/null 2>&1
	@$(call MESSAGE,$(SUCCESS_COL),SDL2 built succesfully!)
