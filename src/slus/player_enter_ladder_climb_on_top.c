#include "types.h"
#include "mmx5/globals.h"

extern void player_clear_dash(u8*);
extern void player_clear_attack(u8*);

void player_enter_ladder_climb_on_top(u8* p) {
    func_8003B33C(p, 0x1D);
    *(s16*)(p + 0x8) = 0;
    *(s16*)(p + 0xC) = 0;
    *(s32*)(p + 0x68) = 0;
    *(u16*)(p + 0xA) = (*(u16*)(p + 0xA) & 0xFFF0) + 8;
    p[0x67] = 1;
    player_clear_dash(p);
    player_clear_attack(p);
    p[0x5] = 0xE;
    p[0x6] = 2;
}
