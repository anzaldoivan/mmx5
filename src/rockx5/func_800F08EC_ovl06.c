#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DED4(u8* obj);
extern u8 D_8009A0A0[];
extern s8 D_8009A0FC;

static inline s32 func_800F08EC_ovl06_hit(u8* obj) {
    if ((*(u16*)(obj + 0x88) & 7) == 4) {
        if (*(u16*)(obj + 0x8A) & 0x80) {
            return 1;
        }
    } else {
        if (D_8009A0FC == -0x80) {
            return 1;
        }
    }
    return 0;
}

void func_800F08EC_ovl06(u8* obj) {
    u8 flags;
    u8 t;
    s32 x;
    u16 t2;
    s32 hit;
    s32 press;
    s32 dir;
    s32 vx;
    u16 pad;
    u16 sides;

    if (*(s8*)(obj + 6) == 0) {
        *(s8*)(obj + 6) = 1;
        *(s32*)(obj + 0x2C) = 0x4200;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        obj[0x96] = 0x28;
        obj[0x67] = 1;
        if (obj[0x97] & 0x40) {
            if (obj[0x8D] == 0) {
                D_8009A0A0[0xD8] = 0x2C;
                D_8009A0A0[6] = 0;
            }
        }
        func_800171E8(obj, 3);
    }
    t = obj[0x97];
    x = t & 0x40;
    flags = t;
    if (x) {
        hit = func_800F08EC_ovl06_hit(obj);
        if (hit) {
            obj[5] = 0xB;
            *(s8*)(obj + 6) = 0;
            return;
        }
    }
    t = 0; // !FAKE: dead reset ends the cse copy equivalence so flags keeps its own register (C0070)
    if (obj[0xA8] & 8) {
        if (flags & 0x40) {
            obj[5] = 5;
        } else {
            obj[0x67] = 0;
            obj[5] = 0xB;
        }
        *(s8*)(obj + 6) = 0;
        return;
    }
    if (flags & 2) {
        return;
    }
    if (flags & 0x40) {
        t2 = *(u16*)(obj + 0x8A);
        x = t2 & 0x30;
        pad = t2;
        if (x) {
            press = 1;
            if (*(s8*)(obj + 2) != 0) {
                press = obj[0x7E] == 0;
            }
        } else {
            press = 0;
        }
        t2 =
            0; // !FAKE: dead reset ends the cse copy equivalence so pad keeps its own register (C0070)
        if (press) {
            obj[5] = 6;
            *(s8*)(obj + 6) = 0;
            return;
        }
        if (*(s8*)(obj + 2) != 0 && obj[0x7D] == 0 && (pad & 0x80)) {
            obj[5] = 0xE;
            *(s8*)(obj + 6) = 0;
            return;
        }
        sides = *(u16*)(obj + 0x88);
        *(s32*)(obj + 0x20) = 0;
        if (sides & 2) {
            obj[0x15] = 0;
            dir = 1;
        } else if (sides & 1) {
            obj[0x15] = 0x40;
            dir = 1;
        } else {
            dir = 0;
        }
        if (dir) {
            vx = *(s16*)(obj + 0x98) << 8;
            if (obj[0x15] == 0) {
                vx = -vx;
            }
            *(s32*)(obj + 0x20) = vx;
        }
        if (*(s32*)(obj + 0x24) < -0x5E000) {
            *(s32*)(obj + 0x24) = -0x5E000;
        }
        func_8002DED4(obj);
    } else {
        func_8002DED4(obj);
    }
}
