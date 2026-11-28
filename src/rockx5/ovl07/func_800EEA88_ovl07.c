#include "types.h"
#include "mmx5/globals.h"

extern void set_stand_animation_by_hp(u8* obj);
extern s16 D_80100540_ovl07[][2];

void func_800EEA88_ovl07(u8* obj) {
    u8* g;
    u8* p;
    s32 c;

    if (*(s8*)(obj + 6) == 0) {
        g = g_playthrough_state.u;
        if (*(s8*)(g + 0x26) == *(s8*)(obj + 7)) {
            g[0x27] |= 2;
            set_stand_animation_by_hp(obj);
            *(s8*)(obj + 0xD0) = -1;
            obj[5] = 0x14;
            return;
        }
        obj[7]++;
        obj[6]++;
        if (*(s8*)(obj + 2) == 0) {
            func_8003B33C(obj, 0x5B);
        } else {
            func_8003B33C(obj, 0x6E);
        }
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x3B;
            p[2] = 1;
            *(s16*)(p + 0xA) =
                *(s16*)(obj + 0xA) + D_80100540_ovl07[*(s8*)(obj + 2)][0];
            *(s16*)(p + 0xE) =
                *(s16*)(obj + 0xE) + D_80100540_ovl07[*(s8*)(obj + 2)][1];
            obj[0x45] &= 0x7F;
        }
    } else if (*(s8*)(obj + 6) == 1) {
        animate_object(obj);
        if (*(s8*)(obj + 0x45) & 0x80) {
            obj[0x45] &= 0x7F;
            return;
        }
        if (*(s8*)(obj + 0x46) == 0) {
            set_stand_animation_by_hp(obj);
            obj[6]++;
        }
    } else {
        animate_object(obj);
        obj[6]++;
        if (*(s8*)(obj + 2) == 0) {
            c = (s8)obj[6] < 0x29;
        } else {
            c = (s8)obj[6] < 0x1F;
        }
        if (!c) {
            obj[6] = 0;
        }
    }
}
