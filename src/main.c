#include "window_display.h"
#include "world.h"
#include "player.h"

int main(int argc, char** argv)
{
    load_level(FIRST_LEVEL);
    
    window_create(argc, argv);
    exit(EXIT_SUCCESS);
}
