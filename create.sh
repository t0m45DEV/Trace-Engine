#!/bin/bash

OPENGL_LIB="glut"

IMG_PARSER_CODE="./imageParser/imageParser.c"
IMG_PARSER="image_parser"

TEXTURE_IMG="./images/textures.png"
TEXTURE_HEADER_DEST="./inc/all_textures.h"
TEXTURE_CODE_DEST="./src/all_textures.c"

TEXTURE_SIZE_NAME="TEXTURE_SIZE"
TEXTURE_MATRIX_NAME="ALL_TEXTURES"

NC='\033[0m' # No Color
RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'

# To print my shit
message() {
    COLOR=$1
    echo -e "${COLOR}>> $2 ${NC}"
}

checkForErrors() {
	
	if [ $? -ne 0 ]; then
		message ${RED} "$1"
		exit 1
	else
		message ${CYAN} "$2"
	fi
}

message ${GREEN} "Welcome to the Tom's 3D engine instalation process!"

CONFIG_OUTPUT="config.log"

message ${NC} "Checking dependencies..."
pkg-config --libs ${OPENGL_LIB} > ${CONFIG_OUTPUT}
checkForErrors "You need the ${OPENGL_LIB} library!" "OpenGL library is installed!"
rm ${CONFIG_OUTPUT}

message ${NC} "Parsing textures..."
gcc ${IMG_PARSER_CODE} -o ${IMG_PARSER} -lm
checkForErrors "There was an error compiling the image parser!" "The texture parser has been compiled!"

./${IMG_PARSER} ${TEXTURE_IMG} ${TEXTURE_HEADER_DEST} ${TEXTURE_CODE_DEST} ${TEXTURE_SIZE_NAME} ${TEXTURE_MATRIX_NAME}
rm ${IMG_PARSER}
checkForErrors "There was an error parsing the textures!" "All textures had been succesfully added!"

message ${NC} "Creating build folder..."
mkdir -p build
message ${CYAN} "Build folder created!"
cd build

message ${NC} "Running CMake..."
cmake ..
checkForErrors "There was an error running CMake!" "CMake succesfully did all it's stuff!"

message ${NC} "Creating executable..."
make all
checkForErrors "There was an error compiling the project!" "Executable created!"

message ${CYAN} "Check the build folder, there's the game executable"
message ${GREEN} "Have fun!"

exit 0
