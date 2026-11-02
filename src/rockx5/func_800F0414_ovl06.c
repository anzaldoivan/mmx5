#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];
extern s8 D_8009A0FC;

void func_800F0414_ovl06(u8* obj) {
    s32 press;
    s32 hit;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        *(s16*)(obj + 0x98) = 0x160;
        func_800171E8(obj, 7);
        if (obj[0x8D] == 0) {
            D_8009A0A0[0xD8] = 0x30;
            D_8009A0A0[6] = 0;
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
    if (!(obj[0x97] & 2)) {
        if (((s8*)obj)[0x46] == 0) {
            obj[5] = 1;
            obj[6] = 0;
        } else if (*(u16*)(obj + 0x8A) & 0x80) {
            obj[5] = 4;
            obj[6] = 0;
        } else {
            if (*(u16*)(obj + 0x8A) & 0x30) {
                press = 1;
                if (((s8*)obj)[2] != 0) {
                    press = obj[0x7E] == 0;
                }
            } else {
                press = 0;
            }
            if (press || (*(u16*)(obj + 0x88) & 3)) {
                obj[5] = 3;
                obj[6] = 0;
            }
        }
        func_80017248(obj);
        return;
    }
    func_80017248(obj);
}
