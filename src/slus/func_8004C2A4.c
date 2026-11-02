#include "types.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

extern void func_80017248(u8* obj);
extern void func_8002D6FC(u8* obj);
extern void func_8004B378(u8* obj);
extern void func_8004B49C(u8* obj, u8* g);
extern void func_8004B8E4(u8* obj, u8* g);
extern void* D_80077504[];
extern u16 D_800E9560;
extern u8 D_8009A0A0[];

void func_8004C2A4(u8* obj) {
    u8* g = D_8009A0A0;
    s8 st;
    s32 f;

    st = FX(obj, s8, 0x99);
    if (st == 0) {
        f = FX(g, s8, 0xD3) != 0;
        if (FX(g, s8, 0xD4)) {
            f = 1;
        }
        if (FX(g, s8, 0xCF)) {
            f = 1;
        }
        if (FX(g, s8, 0x5C) == 0) {
            f = 1;
        }
        if (FX(g, s8, 0xD5)) {
            f = 1;
        }
        if (f) {
            FX(obj, u8, 0x4) = 2;
        }
        ((void (*)(u8*))D_80077504[FX(obj, s8, 0x4)])(obj);
        return;
    }
    if (FX(g, s8, 0xA6) == 0) {
        func_8002D6FC(obj);
        return;
    }
    FX(obj, u8, 0x1) = FX(obj, u8, 0x99);
    FX(obj, s8, 0x0) = -0x7F;
    if (st == 0x22) {
        f = FX(g, s8, 0x5C) == 0;
        if (FX(g, s8, 0xD3)) {
            f = 1;
        }
        if (FX(g, s8, 0xCF)) {
            f = 1;
        }
        if (FX(g, s8, 0x5) != 0x37) {
            f = 1;
        }
        if (f) {
            goto kill; // !FAKE: goto kept for the matching branch layout
        }
        if (FX(obj, s8, 0x4) == 0) {
            func_8004B49C(obj, g);
        } else if (FX(obj, s8, 0x4) == 1) {
            func_80017248(obj);
            if (FX(g, s8, 0x6) != 3) {
                goto keep; // !FAKE: goto kept for the matching branch layout
            }
            goto kill; // !FAKE: goto kept for the matching branch layout
        } else {
            func_80017248(obj);
            if (FX(obj, s8, 0x46) == 0) {
            kill: // !FAKE: label kept for the matching branch layout
                func_8002D6FC(obj);
                FX(obj, u8, 0x3) = 0;
                goto tail; // !FAKE: goto kept for the matching branch layout
            }
        }
    keep: // !FAKE: label kept for the matching branch layout
        func_8004B8E4(obj, g);
        FX(obj, u8, 0x3) = 0;
    } else {
        func_8004B378(obj);
    }
tail: // !FAKE: label kept for the matching branch layout
    if (FX(obj, s8, 0x0)) {
        FX(obj, s32, 0x8) = FX(g, s32, 0x8);
        FX(obj, s32, 0xC) = FX(g, s32, 0xC);
        if (FX(obj, u8, 0x15)) {
            FX(obj, u16, 0xA) += D_800E9560;
        } else {
            FX(obj, u16, 0xA) -= D_800E9560;
        }
        FX(obj, u8, 0x1) = 0x2B;
        FX(obj, u8, 0x0) = 1;
    }
}
