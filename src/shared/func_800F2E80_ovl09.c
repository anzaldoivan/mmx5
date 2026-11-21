#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 func_8002E024(void*, void*);
extern void func_8002E0F8(s32* a0, s32* a1, u8 a2);
extern s16 D_800FB62E_ovl09;
extern s16 D_800FB630_ovl09;
extern s32 D_800FB67C_ovl09;

void func_800F2E80_ovl09(u8* o) {
    u32 max;
    s32 t1;
    s32 t2;
    u16 scale;
    s32 r;
    s16 v;

    if (D_800FB67C_ovl09 != 0) {
        max = 0x60000;
        t1 = 0x1E;
        t2 = 0x3C;
    } else {
        max = 0x40000;
        t1 = 0x23;
        t2 = 0x46;
    }
    *(u32*)(o + 0x84) += *(u32*)(o + 0x88);
    if (max < *(u32*)(o + 0x84)) {
        *(u32*)(o + 0x84) = max;
    }
    scale = *(u16*)(o + 0x86);
    func_8002E0F8((s32*)(o + 0x20), (s32*)(o + 0x24), o[0x92]);
    *(s32*)(o + 0x20) *= scale;
    *(s32*)(o + 0x24) *= scale;
    if (*(s16*)(o + 0x7C) == t1) {
        r = func_8002E024(o, g_Player);
        o[0x92] = r;
        if ((u8)r < 9) {
            o[0x92] = 0x1F;
        } else if ((u8)(r - 9) < 8) {
            o[0x92] = 0x11;
        }
    }
    if (++*(s16*)(o + 0x7C) == t2 || o[0x93] != 0) {
        set_animation(o, 0);
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x24) = 0x30000;
        o[6]++;
    }
    animate_object(o);
    apply_object_motion(o);
    if (*(s16*)(o + 0xA) < D_800FB62E_ovl09 - 8) {
        *(s16*)(o + 0xA) = D_800FB62E_ovl09 - 8;
    } else if (D_800FB630_ovl09 + 8 < *(s16*)(o + 0xA)) {
        *(s16*)(o + 0xA) = D_800FB630_ovl09 + 8;
    }
}
