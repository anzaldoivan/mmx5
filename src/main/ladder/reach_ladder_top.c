#include "types.h"
#include "mmx5/globals.h"

extern void player_clear_attack(u8*);

void reach_ladder_top(u8* p) {
    func_8003B33C(p, 0x1C);
    *(s32*)(p + 0x68) = 0;
    *(s16*)(p + 0xC) = 0;
    *(u16*)(p + 0xE) &= 0xFFF0;
    player_clear_attack(p);
    p[0x5] = 0xE;
    p[0x6] = 1;
}
