#include "types.h"
#include "mmx5/globals.h"

u16 map_buttons(u16 mask);

void read_player_input(void) {
    u8* dst = g_Player;
    u16* src = D_800C931C;

    *(u16*)(dst + 0x7C) = map_buttons(src[0]);
    *(u16*)(dst + 0x7E) = map_buttons(src[1]);
    *(u16*)(dst + 0x80) = map_buttons(src[2]);
}
