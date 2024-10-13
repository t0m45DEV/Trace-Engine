#!/bin/bash

NC='\033[0m' # No Color
RED='\033[0;30m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'

# To print my shit
message() {
    COLOR=$1
    echo -e "${COLOR}>> $2 ${NC}"
}

message ${GREEN} "Welcome to the Tom's 3D engine instalation process!"

message ${NC} "Creating build folder..."
mkdir -p build
message ${CYAN} "Build folder created!"
cd build

message ${NC} "Running CMake..."
cmake ..
message ${CYAN} "CMake succesfully did all it's stuff!"

message ${NC} "Creating executable..."
make all
message ${GREEN} "Executable created!"

message ${CYAN} "Check the build folder, there's the game executable"
message ${GREEN} "Have fun!"
