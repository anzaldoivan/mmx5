#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8* func_8002D078();
extern void func_8002DED4(u8* obj);
extern u8 D_8009A0A0[];

void func_800EFF34_ovl06(u8* arg0) {
    s32 v;
    u16 f;
    u8 c;
    u8* o;
    u8* g;

    if (*(s8*)(arg0 + 6) == 0) {
        arg0[6] = 1;
        o = func_8002D078();
        if (o != 0) {
            o[0] = 0x41;
            o[1] = 0x3E;
            o[2] = 3;
            *(u16*)(o + 0xA) = *(u16*)(arg0 + 0xA);
            *(u16*)(o + 0xE) = *(u16*)(arg0 + 0xE);
            *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
            *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
            *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
            *(u16*)(o + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
            o[0x16] = arg0[0x16];
            *(u8**)(o + 0x7C) = arg0;
            o[0x15] = arg0[0x15];
        }
        func_800171E8(arg0, 0xB);
        if (arg0[0x8D] == 0) {
            g = D_8009A0A0;
            g[0xD8] = 0x33;
            g[6] = 0;
        }
        func_80016490(5, 0x10, 0);
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
        if (*(s32*)(arg0 + 0x24) >= 0 &&
            ((arg0[0xA8] & 4) || !(*(u16*)(arg0 + 0x88) & 0x80))) {
            *(s32*)(arg0 + 0x24) = 0;
        }
        if (*(s8*)(arg0 + 0x46) == 0) {
            c = 4;
            if (*(s32*)(arg0 + 0x24) < 0) {
                c = 0xC;
            }
            arg0[5] = c;
        } else {
            if (*(s32*)(arg0 + 0x24) < -0x5E000) {
                *(s32*)(arg0 + 0x24) = -0x5E000;
            }
            func_8002DED4(arg0);
        }
        func_80017248(arg0);
        return;
    }
    func_80017248(arg0);
}
