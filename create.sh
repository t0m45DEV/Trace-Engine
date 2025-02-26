#!/bin/bash

BUILD_FOLDER="build"

OPENGL_LIB="sdl2 gl"

IMG_PARSER_CODE="./imageParser/imageParser.c"
IMG_PARSER="image_parser"

TEXTURE_IMG="./textures/structures.png"
TEXTURE_HEADER_DEST="./inc/all_textures.h"
TEXTURE_CODE_DEST="./src/all_textures.c"

TEXTURE_SIZE_NAME="TEXTURE_SIZE"
TEXTURE_MATRIX_NAME="ALL_TEXTURES"

NC='\033[0m' # No Color
RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'

CONFIG_OUTPUT="config.log" # To put programs output

# To print my shit
message() {
    COLOR=$1
    echo -e ">>${COLOR} $2 ${NC}"
}

checkForErrors() {
	
	if [ $? -ne 0 ]; then
		message ${RED} "$1"
		exit 1
	else
		message ${CYAN} "$2"
	fi
}

#
# To run this function use this template:
#
# declare -a FUNCTION_TO_RUN=(
#     "Wait message"
#     "bash command"
#     "Error message"
#     "Good message"
# )
# runFunction "${FUNCTION_TO_RUN}"
#
runFunction() {
	local arr=("$@")

	message ${NC} "${arr[0]}"
	eval "${arr[1]}"
	checkForErrors "${arr[2]}" "${arr[3]}"
}

message ${GREEN} "Welcome to the Tom's 3D engine instalation process!"

declare -a CHECK_DEPENDENCIES=(
	"Checking dependencies..."
	"pkg-config --libs ${OPENGL_LIB} > ${CONFIG_OUTPUT}"
	"You need the ${OPENGL_LIB} library!"
	"OpenGL library is installed!"
)
runFunction "${CHECK_DEPENDENCIES[@]}"
rm ${CONFIG_OUTPUT}

declare -a COMPILE_TEXTURE_PARSER=(
	"Compiling texture parser..."
	"gcc ${IMG_PARSER_CODE} -o ${IMG_PARSER} -lm"
	"There was an error compiling the image parser!"
	"The texture parser has been compiled!"
)
runFunction "${COMPILE_TEXTURE_PARSER[@]}"

declare -a RUN_TEXTURE_PARSER=(
	"Parsing images to the game..."
	"./${IMG_PARSER} ${TEXTURE_IMG} ${TEXTURE_HEADER_DEST} ${TEXTURE_CODE_DEST} ${TEXTURE_SIZE_NAME} ${TEXTURE_MATRIX_NAME}"
	"There was an error parsing the textures!"
	"All textures had been succesfully added!"
)
runFunction "${RUN_TEXTURE_PARSER[@]}"
rm ${IMG_PARSER}

declare -a CREATE_BUILD_FOLDER=(
	"Creating build folder..."
	"mkdir -p ${BUILD_FOLDER}"
	"There was an error creating the build folder!"
	"Build folder created!"
)
runFunction "${CREATE_BUILD_FOLDER[@]}"
cd ${BUILD_FOLDER}

declare -a RUN_CMAKE=(
	"Running CMake..."
	"cmake .."
	"There was an error running CMake!"
	"CMake succesfully did all it's stuff!"
)
runFunction "${RUN_CMAKE[@]}"

declare -a COMPILE_PROJECT=(
	"Compiling project..."
	"make videoGame"
	"There was an error compiling the project!"
	"Executable created!"
)
runFunction "${COMPILE_PROJECT[@]}"

declare -a COMPILE_TESTS=(
	"Compiling tests runner..."
	"make run_tests"
	"Ironic, there's something wrong in the tests program..."
	"Tests program succesfully created!"
)
runFunction "${COMPILE_TESTS[@]}"

declare -a RUN_TESTS=(
	"Running tests..."
	"./run_tests"
	"It appears we have some bugs to catch!"
	"Every test passed!"
)
runFunction "${RUN_TESTS[@]}"

message ${CYAN} "Check the build folder, there's the game executable"
message ${GREEN} "Have fun!"

exit 0
