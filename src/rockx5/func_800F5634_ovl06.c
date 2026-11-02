#include "types.h"

extern u8* func_8002D0E4(void);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern s16 D_8009A0AA;

void func_800F5634_ovl06(u8* obj) {
    u8* n;
    u8 t;
    u8 f;
    u8 c;
    s32 st;

    if (*(s8*)(obj + 6) == 0) {
        if (*(s8*)(obj + 2) == 0) {
            if (obj[0x8A] != 0) {
                if (obj[0x8A] & 1) {
                    obj[0x15] = 0x40;
                } else {
                    obj[0x15] = 0;
                }
            }
        } else if (*(s16*)(obj + 0xA) - D_8009A0AA < 0) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        obj[6] = 1;
        *(s16*)(obj + 0x84) = 0x420;
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = 0x42000;
        } else {
            *(s32*)(obj + 0x20) = -0x42000;
        }
        obj[0x8E] = 0x1E;
        n = func_8002D0E4();
        if (n != 0) {
            t = obj[0];
            n[1] = 0xC;
            n[2] = 5;
            n[0] = t;
            *(s32*)(n + 8) = *(s32*)(obj + 8);
            *(s32*)(n + 0xC) = *(s32*)(obj + 0xC);
            *(s32*)(n + 0x30) = *(s32*)(obj + 0x30);
            *(s16*)(n + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(n + 0x3C) = *(s32*)(obj + 0x3C);
            *(s16*)(n + 0x42) = *(s16*)(obj + 0x42) & 0x7FFF;
            n[0x16] = obj[0x16];
            n[0x15] = obj[0x15];
            *(u8**)(n + 0x50) = obj;
        }
        func_800171E8(obj, 5);
        obj[0x8D] |= 4;
    }
    if (!(obj[0x8D] & 2)) {
        if (obj[0x86] != 0) {
            st = 8;
        } else if (obj[0x87] != 0) {
            st = 0xB;
        } else {
            f = obj[0x70];
            if (f & 8) {
                goto test3; // !FAKE: goto kept for the matching branch layout
            }
            st = 4;
        }
        obj[5] = st;
        obj[6] = 0;
        goto call; // !FAKE: goto kept for the matching branch layout
    test3:
        if (!(f & 3)) {
            *(s32*)(obj + 8) += *(s32*)(obj + 0x20);
            c = obj[0x8E];
            obj[0x8E] = c - 1;
            if ((s8)c >= 0) {
                goto call; // !FAKE: goto kept for the matching branch layout
            }
        }
        obj[5] = 7;
        obj[6] = 0;
        return;
    call:
        func_80017248(obj);
        return;
    }
    func_80017248(obj);
}
