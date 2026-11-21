#include "types.h"
#include "mmx5/globals.h"

extern s32 get_tile_attr_origin(u8* obj);
extern void player_enter_ladder_shoot(u8*);
extern void func_8003B0EC(u8*);

s32 try_grab_ladder_from_air(u8* obj) {
    if (*(s8*)(obj + 0xD3) != 0) {
        return 0;
    }
    if (!(*(u16*)(obj + 0x7C) & 4)) {
        return 0;
    }
    if (get_tile_attr_origin(obj) != 0x20) {
        return 0;
    }
    if (*(s8*)(obj + 0x8E) != 0) {
        player_enter_ladder_shoot(obj);
    } else {
        func_8003B33C(obj, 0x1F);
        func_8003B0EC(obj);
    }
    return 1;
}
