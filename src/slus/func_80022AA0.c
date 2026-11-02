#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];

void func_80022AA0(u8* arg0) {
    u8* p;
    s32 kind;
    s32 want;
    s32 v;

    p = D_8009A0A0;
    kind = *(s8*)(arg0 + 2);
    *(s32*)(arg0 + 0x8) = *(s32*)(p + 0x8);
    *(s32*)(arg0 + 0xC) = *(s32*)(p + 0xC);
    if (kind == 2) {
        if (*(s8*)(p + 0x8C) != 0 && (*(s32*)(p + 4) & 0xFFFF00) == 0x10C00) {
            arg0[3] = 1;
            arg0[0x15] = p[0x15];
            func_80017248(arg0);
            return;
        }
        func_800171E8(arg0, 0x2A);
        arg0[3] = 0;
        return;
    }
    if (kind == 3) {
        if (*(s8*)(p + 5) == 0x23 && *(s8*)(p + 6) > 0) {
            arg0[3] = 1;
            if (*(s8*)(arg0 + 6) != (v = *(s8*)(p + 6))) {
                arg0[6] = p[6];
                if (v == 1) {
                    func_80017214(arg0, 0x2A, *(s8*)(arg0 + 0x45));
                } else {
                    func_80017214(arg0, v + 0x28, *(s8*)(arg0 + 0x45));
                }
            }
            arg0[0x15] = p[0x15];
            func_80017248(arg0);
            return;
        }
        func_800171E8(arg0, 0x2A);
        arg0[6] = 2;
        arg0[3] = 0;
        return;
    }
    if (*(s8*)(arg0 + 4) == 0) {
        want = 1;
        if (kind == 0) {
            want = 2;
        }
        if (*(s8*)(p + 0x9B) == want || *(s8*)(p + 0x9C) == want) {
            arg0[3] = 1;
            func_800171E8(arg0, kind + 8);
            arg0[4]++;
        }
    } else {
        if (*(s8*)(p + 0x9B) == 0 && *(s8*)(p + 0x9C) == 0) {
            arg0[3] = 0;
            arg0[4] = 0;
            return;
        }
        func_80017248(arg0);
    }
}
