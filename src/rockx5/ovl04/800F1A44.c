#include "types.h"
#include "mmx5/movement.h"

void func_800F1A44_ovl04(u8* a0) {
    s32 n;

    n = *(u16*)(a0 + 0x7E) - 1;
    *(u16*)(a0 + 0x7E) = n;
    if ((n << 16) == 0) {
        *(u16*)(a0 + 0x86) = *(u16*)(a0 + 0xE);
        *(s32*)(a0 + 0x2C) = -*(s32*)(a0 + 0x2C);
        a0[0x81]++;
    }
}

void func_800F1A88_ovl04(u8* obj) {
    Fix0418
        d; // the s32 view keeps the pair in a register; only the high half is used

    apply_object_motion(obj);
    if (*(s32*)(obj + 0x24) < 0) {
        d.h.hi = *(u16*)(obj + 0xE) - *(u16*)(obj + 0x86);
    } else {
        d.h.hi = *(u16*)(obj + 0x86) - *(u16*)(obj + 0xE);
    }
    if (d.h.hi >= 0x30) {
        *(u16*)(obj + 0x86) = *(u16*)(obj + 0xE);
        *(s32*)(obj + 0x2C) = -*(s32*)(obj + 0x2C);
        obj[0x81]++;
    }
}

void func_800F1B1C_ovl04(u8* o) {
    *(s16*)(o + 0x7E) = 0x1E;
    *(s32*)(o + 0x24) = 0;
    o[0x81]++;
}
