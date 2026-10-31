#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];
extern s8 D_8009A0FC;

void func_800F1C0C_ovl06(u8* obj) {
    s32 hit;
    s32 press;
    s32 moved;
    u16 pad;
    s32 x;
    u16 t;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        obj[0x7D] = 1;
        *(s16*)(obj + 0x98) = 0x160;
        func_800171E8(obj, 0xD);
        if (obj[0x8D] == 0) {
            D_8009A0A0[0xD8] = 0x3C;
            D_8009A0A0[6] = 0;
        }
        obj[0x87] = 0;
        func_80016490(5, 5, 0);
    }

    t = *(u16*)(obj + 0x88);
    x = t & 7;
    pad = t;
    if (x == 4) {
        if (!(*(u16*)(obj + 0x8A) & 0x80)) {
            goto zero; // !FAKE: goto kept for the matching branch layout
        }
        hit = 1;
    } else if (D_8009A0FC == -0x80) {
        hit = 1;
    } else {
    zero:
        hit = 0;
    }
    t = 0; // !FAKE: dead reset ends the cse copy equivalence so pad keeps its own register (C0070)
    if (hit) {
        obj[5] = 0xB;
        obj[6] = 0;
        return;
    }
    if (obj[0xA8] & 8) {
        obj[5] = 5;
        obj[6] = 0;
        return;
    }
    if (!(obj[0x97] & 2)) {
        if (*(u16*)(obj + 0x8A) & 0x80) {
            obj[5] = 0xC;
            obj[6] = 0;
            return;
        }
        if (*(u16*)(obj + 0x8A) & 0x30) {
            press = 1;
            if (((s8*)obj)[2] != 0) {
                press = obj[0x7E] == 0;
            }
        } else {
            press = 0;
        }
        if (press) {
            obj[5] = 0x11;
            obj[6] = 0;
            return;
        }
        if (pad & 2) {
            obj[0x15] = 0;
            moved = 1;
        } else if (pad & 1) {
            obj[0x15] = 0x40;
            moved = 1;
        } else {
            moved = 0;
        }
        if (moved) {
            if (obj[0x15]) {
                *(s32*)(obj + 0x20) = 0x16000;
            } else {
                *(s32*)(obj + 0x20) = -0x16000;
            }
            *(s32*)(obj + 8) += *(s32*)(obj + 0x20);
        }
        func_80017248(obj);
        return;
    }
    func_80017248(obj);
}
