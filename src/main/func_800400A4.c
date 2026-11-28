#include "types.h"
#include "mmx5/globals.h"

extern void set_stand_animation_by_hp(u8* obj);
extern void func_80040738(u8* obj);
#define D_800D1C00_as_D1C00 (*(D1C00*)&g_playthrough_state)

void func_800400A4(u8* obj) {
    if (((s8*)obj)[2] == 0) {
        if (((s8*)obj)[0x8F] != 0) {
            func_80040738(obj);
            return;
        }
        if (((s8*)obj)[0x90] != 0) {
            set_stand_animation_by_hp(obj);
            return;
        }
    }
    if (obj[0x17] == 6 &&
        ((s8*)obj)[0x5C] >=
            (s8)(D_800D1C00_as_D1C00.unk47[((s8*)obj)[2]] / 3)) {
        func_8003B33C(obj, 5);
        return;
    }
    animate_object(obj);
}
