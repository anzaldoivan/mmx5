#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern s32 func_8002B5B4(s32);
extern u8* func_8002D078();
extern u8 D_8009A0A0[];

void func_800F1838_ovl06(u8* arg0) {
    u8* o;
    s32 r;
    s32 v;
    s32 m;
    u16 c;
    s32 t;
    s8 st;

    st = ((s8*)arg0)[6];
    if (st == 0) {
        arg0[6] = st + 1;
        if (*(u16*)(arg0 + 0x88) & 8) {
            if (arg0[0x86] < 3) {
                o = func_8002D078();
                if (o != 0) {
                    o[0] = 0x41;
                    o[1] = 0x3B;
                    o[2] = 1;
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
            func_800171E8(arg0, 10);
            if (arg0[0x8D] == 0) {
                D_8009A0A0[0xD8] = 0x37;
                D_8009A0A0[6] = 0;
            }
        } else if (arg0[0x86] < 3) {
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
        func_80016490(5, 7, 0);
    }
    t = arg0[0x90] - 1;
    arg0[0x90] = t;
    if (!(arg0[0x97] & 2)) {
        if ((arg0[0xA8] & 3) || (s8)t < 0) {
            arg0[5] = 12;
            arg0[6] = 0;
        } else if (((s8*)arg0)[0x46] == 0) {
            arg0[5] = 15;
            arg0[6] = 1;
            *(s32*)(arg0 + 8) += *(s32*)(arg0 + 0x20);
        } else {
            if (!(arg0[0x97] & 8)) {
                c = arg0[0x15] ? 1 : 2;
                c = *(u16*)(arg0 + 0x88) & c;
            } else {
                m = arg0[0x15] ? 1 : 2;
                c = *(u16*)(arg0 + 0x88) & m;
                if (c == 0) {
                    c = *(u16*)(arg0 + 0x88) & 0x100;
                }
            }
            if (c) {
                *(s32*)(arg0 + 8) += *(s32*)(arg0 + 0x20);
            }
            v = 0;
            if (*(u16*)(arg0 + 0x8A) & 0x30) {
                v = 1;
                if (((s8*)arg0)[2] != 0) {
                    v = arg0[0x7E] == 0;
                }
            }
            if (v != 0 && arg0[0x86] < 3) {
                arg0[5] = 0x10;
                arg0[6] = 0;
                if (*(u16*)(arg0 + 0x88) & 8) {
                    func_800171E8(arg0, 10);
                } else {
                    func_800171E8(arg0, 12);
                }
            }
        }
        func_80017248(arg0);
    } else {
        func_80017248(arg0);
    }
}
