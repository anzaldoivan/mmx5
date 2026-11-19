#include "types.h"
#include "mmx5/globals.h"

extern void player_clear_attack(u8*);

void player_enter_ladder_step_off_bottom(u8* p) {
    func_8003B33C(p, 0x1E);
    player_clear_attack(p);
    p[0x5] = 0xE;
    p[0x6] = 3;
}
