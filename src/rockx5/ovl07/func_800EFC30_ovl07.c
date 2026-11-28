#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

void func_800EFC30_ovl07(u8* obj) {
    u32 v;
    u8* base;
    s8* p;

    if ((u32)(obj[6] - 1) < 4) {
        base = D_8009A1F8.u;
        v = *(s32*)(obj + 0x94) + *(s32*)(obj + 0x90);
        *(s32*)(obj + 0x94) = v;
        (base + ((s8*)obj)[0x14] * 0x54)[0x47] -= v >> 16;
        p = (s8*)(base + ((s8*)obj)[0x14] * 0x54);
        if (p[0x47] < 6) {
            p[0x47] = 6;
        }
    }
    apply_object_motion(obj);
}
