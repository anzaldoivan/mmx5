#include "types.h"
#include "mmx5/globals.h"

extern s32 get_tile_attr_origin(u8* obj);
extern void player_enter_ladder_step_off_bottom(u8* obj);
extern void reach_ladder_top(u8* obj);

s32 try_leave_ladder(u8* obj) {
    s32 r;
    s32 t;

    r = get_tile_attr_origin(obj);
    if (obj[0x89] & 8) {
        player_enter_ladder_step_off_bottom(obj);
        return 1;
    }
    if ((*(u16*)(obj + 0x7C) & 4) && r == 0x21) {
        reach_ladder_top(obj);
        return 1;
    }
    t = (u8)(r - 0x20) >= 2;
    if (*(u16*)(obj + 0x80) & 0x80) {
        t = 1;
    }
    if (t != 0) {
        func_8003B33C(obj, 0x1E);
        obj[5] = 0xE;
        obj[6] = 4;
        return 1;
    }
    return 0;
}
