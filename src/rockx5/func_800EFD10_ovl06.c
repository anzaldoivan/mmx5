#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern void func_80016D54(s32, s32);
extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];
extern s8 D_8009A0FC;

void func_800EFD10_ovl06(u8* obj) {
    s32 hit;
    s32 press;
    s32 moved;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        *(s16*)(obj + 0x98) = 0x160;
        obj[0x67] = 0;
        obj[0x7D] = 0;
        func_800171E8(obj, 4);
        if (obj[0x8D] == 0) {
            D_8009A0A0[0xD8] = 0x2D;
            D_8009A0A0[6] = 0;
        }
        obj[0xA8] |= 8;
        if (((s8*)obj)[2] == 0) {
            func_80016490(5, 0xD, 0);
        } else {
            func_80016490(5, 0, 0);
            func_80016D54(5, 5);
            func_80016490(5, 0, 0);
        }
    }

    if ((*(u16*)(obj + 0x88) & 7) == 4) {
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
    if (hit) {
        obj[5] = 0xB;
        obj[6] = 0;
        return;
    }
    if (((s8*)obj)[0x46] == 0) {
        obj[5] = 1;
        obj[6] = 0;
        return;
    }
    if (!(obj[0x97] & 2)) {
        if (!(obj[0xA8] & 8)) {
            obj[5] = 0xC;
            obj[6] = 0;
        } else {
            press = 0;
            if (*(u16*)(obj + 0x8A) & 0x30) {
                press = 1;
                if (((s8*)obj)[2] != 0) {
                    press = obj[0x7E] == 0;
                }
            }
            if (press) {
                obj[5] = 3;
                obj[6] = 0;
            } else {
                if (*(u16*)(obj + 0x88) & 2) {
                    obj[0x15] = 0;
                    moved = 1;
                } else if (*(u16*)(obj + 0x88) & 1) {
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
            }
        }
        func_80017248(obj);
        return;
    }
    func_80017248(obj);
}
