#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern s32 func_8002B5B4(s32);
extern u8* func_8002D078();
extern s8 D_8009A0FC;

void func_800F0EB4_ovl06(u8* arg0) {
    s32 flag;
    u32 i;
    u8 bits;
    u8* o;
    u8 k;
    s32 r;

    if ((*(u16*)(arg0 + 0x88) & 7) == 4) {
        flag = 1;
        if (*(u16*)(arg0 + 0x8A) & 0x80) {
        } else {
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        flag = 1;
        if (D_8009A0FC != -0x80) {
        clear:
            flag = 0;
        }
    }
    if (flag != 0) {
        arg0[5] = 0xB;
        arg0[6] = 0;
        return;
    }
    if (!(arg0[0x97] & 2)) {
        if (!(arg0[0xA8] & 8)) {
            arg0[5] = 0xC;
            arg0[6] = 0;
        } else {
            if (*(u16*)(arg0 + 0x88) & 2) {
                arg0[0x15] = 0;
            } else if (*(u16*)(arg0 + 0x88) & 1) {
                arg0[0x15] = 0x40;
            }
            if (!(arg0[0x97] & 0x10) && arg0[0x94] == 0) {
                bits = arg0[0x7F];
                arg0[6] = 5;
                for (i = 0; i < 3; i++) {
                    if (!(bits & 1)) {
                        k = i;
                        if (arg0[0x86] < 3) {
                            o = func_8002D078();
                            if (o != 0) {
                                o[0] = 0x41;
                                o[1] = 0x3C;
                                o[2] = k;
                                *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
                                *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
                                *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
                                *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
                                *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
                                r = func_8002B5B4(0x81) & 0xFF;
                                *(s16*)(o + 0x42) =
                                    ((r * 4 + 0x18) % 16) |
                                    (((r + 6) / 4 + 0x1E0) << 6);
                                o[0x16] = arg0[0x16];
                                *(u8**)(o + 0x7C) = arg0;
                                o[0x15] = arg0[0x15];
                            }
                        }
                        arg0[0x7F] |= 1 << i;
                    }
                    bits >>= 1;
                }
                arg0[0x7E] = 0x10;
                func_80016490(5, 6, 0);
            }
        }
        func_80017248(arg0);
        return;
    }
    func_80017248(arg0);
}
