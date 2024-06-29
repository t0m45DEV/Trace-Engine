#include "window_display.h"
#include "world.h"
#include "player.h"

int main(int argc, char** argv)
{
    current_level = FIRST_LEVEL;
    set_level_info(current_level);
    reset_player_info();
    window_create(argc, argv);
    return 0;
}
