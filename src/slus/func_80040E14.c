#include "types.h"
#include "mmx5/object.h"

extern s32 player_nova_strike_hit_wall(u8* obj);
extern void func_8003C5D8(u8* obj);
extern void func_8003AA4C(u8* arg0);
extern s8 D_800D1C1C;

void func_80040E14(u8* obj) {
    s32 f;
    u8 t;

    f = player_nova_strike_hit_wall(obj) != 0;
    t = obj[0xF4];
    if (t == 0) {
        f = 1;
    }
    if (f) {
        if (*(s8*)(obj + 0xD3) == 0) {
            obj[0x7A] = 0;
        }
        obj[0xF3] = 0;
        D_800D1C1C = 0;
        func_8003C5D8(obj);
        func_8003AA4C(obj);
    } else {
        obj[0xF4] = t - 1;
        move_object(obj);
    }
}
