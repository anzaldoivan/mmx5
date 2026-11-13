#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern s32 func_8002B5B4(s32);
extern void func_8002DED4(u8* obj);
extern u8* func_8002D078();
extern u8 D_8009A0A0[];

void func_800F12E8_ovl06(u8* arg0) {
    u8* o;
    s32 r;
    s32 v;
    s32 hit;
    u16 f;
    s32 one;

    if (((s8*)arg0)[6] == 0) {
        arg0[6] = 1;
        if (*(u16*)(arg0 + 0x88) & 8) {
            func_800171E8(arg0, 9);
            if (arg0[0x8D] == 0) {
                D_8009A0A0[0xD8] = 0x33;
                D_8009A0A0[6] = 0;
            }
            if (arg0[0x86] < 3) {
                o = func_8002D078();
                one = 1;
                if (o != 0) {
                    o[0] = 0x41;
                    o[1] = 0x3B;
                    o[2] = one;
                    *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
                    *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
                    *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
                    *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
                    *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
                    r = func_8002B5B4(0x81) & 0xFF;
                    *(s16*)(o + 0x42) =
                        ((r * 4 + 0x18) % 16) | (((r + 6) / 4 + 0x1E0) << 6);
                    o[0x16] = arg0[0x16];
                    *(u8**)(o + 0x7C) = arg0;
                    o[0x15] = arg0[0x15];
                    arg0[0x86]++;
                }
            }
        } else {
            if (arg0[0x86] < 3) {
                o = func_8002D078();
                if (o != 0) {
                    o[0] = 0x41;
                    o[1] = 0x3B;
                    o[2] = 0;
                    *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
                    *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
                    *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
                    *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
                    *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
                    r = func_8002B5B4(0x81) & 0xFF;
                    *(s16*)(o + 0x42) =
                        ((r * 4 + 0x18) % 16) | (((r + 6) / 4 + 0x1E0) << 6);
                    o[0x16] = arg0[0x16];
                    *(u8**)(o + 0x7C) = arg0;
                    o[0x15] = arg0[0x15];
                    arg0[0x86]++;
                }
            }
        }
        func_80016490(5, 7, 0);
    }
    if (arg0[0xA8] & 8) {
        arg0[5] = 5;
        arg0[6] = 0;
        return;
    }
    if (!(arg0[0x97] & 2)) {
        f = *(u16*)(arg0 + 0x88);
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        if (f & 3) {
            v = *(s16*)(arg0 + 0x98) << 8;
            if (!(f & 1)) {
                v = -v;
            }
            *(s32*)(arg0 + 0x20) = v;
        }
        if (*(s32*)(arg0 + 0x24) >= 0) {
            if ((arg0[0xA8] & 4) || !(*(u16*)(arg0 + 0x88) & 0x80)) {
                *(s32*)(arg0 + 0x24) = 0;
            }
        }
        if (((s8*)arg0)[0x46] == 0) {
            arg0[5] = (*(s32*)(arg0 + 0x24) < 0) ? 0xC : 4;
        } else {
            if (*(s32*)(arg0 + 0x24) < -0x5E000) {
                *(s32*)(arg0 + 0x24) = -0x5E000;
            }
            func_8002DED4(arg0);
            if (((s8*)arg0)[0x45] != 0) {
                hit = 0;
                if (*(u16*)(arg0 + 0x8A) & 0x30) {
                    hit = 1;
                    if (((s8*)arg0)[2] != 0) {
                        hit = arg0[0x7E] == 0;
                    }
                }
                if (hit != 0 && arg0[0x86] < 3) {
                    arg0[5] = 6;
                    arg0[6] = 0;
                }
            }
        }
        func_80017248(arg0);
    } else {
        func_80017248(arg0);
    }
}
