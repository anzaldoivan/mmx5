#include "types.h"

extern s32 get_tile_attr_top(u8* obj);
extern void func_8003AF74(u8* obj);
extern s32 get_tile_attr_below(u8* obj);
extern void player_enter_ladder_climb_on_top(u8* obj);

s32 try_enter_ladder(u8* obj) {
    if (*(s8*)(obj + 0xD3) != 0) {
        return 0;
    }
    if (obj[0x92] != 0) {
        return 0;
    }
    if ((*(u16*)(obj + 0x7C) & 4) && get_tile_attr_top(obj) == 0x20) {
        func_8003AF74(obj);
        return 1;
    }
    if (*(u16*)(obj + 0x7C) & 8) {
        if (get_tile_attr_below(obj) == 0x21) {
            player_enter_ladder_climb_on_top(obj);
            return 1;
        }
    }
    return 0;
}
