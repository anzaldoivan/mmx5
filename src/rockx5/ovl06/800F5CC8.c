#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FE914_ovl06[];
extern u8 D_800FE918_ovl06[];
extern u8 D_800FE924_ovl06[];

void func_800F5CC8_ovl06(u8* obj) {
    if (*(s8*)(obj + 6) == 0) {
        obj[6]++;
        set_animation(obj, 9);
    }
    if (*(s8*)(obj + 0x46) == 0) {
        obj[5] = 2;
        obj[6] = 0;
        obj[0x88] = 0;
        obj[0x86] = 0;
        *(u8**)(obj + 0x54) = D_800FE914_ovl06;
        *(u8**)(obj + 0x50) = D_800FE918_ovl06;
        obj[0x60] = 5;
        obj[0x87] = 0;
        return;
    }
    if (*(s8*)(obj + 0x45) == 1) {
        *(u8**)(obj + 0x50) = D_800FE924_ovl06;
        obj[0x60] = 6;
    } else if (*(s8*)(obj + 0x45) == 2) {
        *(u8**)(obj + 0x50) = D_800FE918_ovl06;
        obj[0x60] = 5;
    }
    animate_object(obj);
}

extern u8 D_800FE914_ovl06[];
extern u8 D_800FE918_ovl06[];

void func_800F5D90_ovl06(u8* obj) {
    u8 v;
    s32 r;
    s32 q;

    if (*(s8*)(obj + 6) == 0) {
        obj[6] = 1;
        *(s16*)(obj + 0x84) = 0x160;
        set_animation(obj, 6);
        *(u8**)(obj + 0x54) = D_800FE914_ovl06;
        *(u8**)(obj + 0x50) = D_800FE918_ovl06;
        obj[0x60] = 5;
        obj[0x8D] &= 0xFB;
    }
    if (!(obj[0x8D] & 2)) {
        if (*(s8*)(obj + 0x46) == 0) {
            r = 2;
            obj[5] = r;
            do {
                r = (s32)D_800FE914_ovl06;
            } while (0); // !FAKE: fences the sched1 hoist of the address loads
            q = (s32)D_800FE918_ovl06;
            *(s32*)(obj + 0x54) = r;
            obj[6] = 0;
            obj[0x88] = 0;
            obj[0x86] = 0;
            obj[0x87] = 0;
            *(s32*)(obj + 0x50) = q;
            obj[0x60] = 5;
            return;
        }
        if (obj[0x86] != 0) {
            v = 8;
        } else if (obj[0x87] != 0) {
            v = 9;
        } else if (obj[0x8A] != 0) {
            v = 3;
        } else {
            goto call; // !FAKE: goto kept for the matching branch layout
        }
        obj[5] = v;
        obj[6] = 0;
        return;
    call: // !FAKE: label kept for the matching branch layout
        animate_object(obj);
        return;
    }
    animate_object(obj);
}

extern u8 D_800FE920_ovl06[];

void func_800F5EB0_ovl06(u8* o) {
    u8 f70;
    u8 f8D;
    s32 t;

    if (*(s8*)(o + 6) == 0) {
        o[6] = 1;
        set_animation(o, 8);
        *(u8**)(o + 0x50) = D_800FE920_ovl06;
        o[0x60] = 6;
        o[0x8D] |= 8;
    }
    t = o[0x8E] - 1;
    f70 = o[0x70];
    o[0x8E] = t;
    if (!(f70 & 8)) {
        o[5] = 4;
        o[6] = 0;
        return;
    }
    f8D = o[0x8D];
    if (!(f8D & 2)) {
        if ((f70 & 3) || (o[0x45] & 1)) {
            if ((s8)t < 0) {
                o[5] = 7;
                o[6] = 0;
                o[0x8D] = f8D & 0xF7;
            } else {
                *(s32*)(o + 8) += *(s32*)(o + 0x20);
            }
        }
        animate_object(o);
        return;
    }
    animate_object(o);
}

extern u8 D_800FE914_ovl06[];
extern u8 D_800FE918_ovl06[];

void func_800F5FAC_ovl06(u8* arg0) {
    arg0[5] = 2;
    arg0[6] = 0;
    arg0[0x88] = 0;
    arg0[0x86] = 0;
    arg0[0x87] = 0;
    *(u8**)(arg0 + 0x54) = D_800FE914_ovl06;
    *(u8**)(arg0 + 0x50) = D_800FE918_ovl06;
    arg0[0x60] = 5;
}
