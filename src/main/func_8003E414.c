#include "types.h"

extern void func_8003F608();
extern void func_8003F70C(u8* a0);
extern void func_8003F7F8(u8* arg0, s32 arg1);
extern s8 D_80074B98[];
extern s8 D_80074B60[];
extern s8 D_80074BD0[];
extern s8 D_800749D8[];
extern void* D_80074AA0[];
extern u8 D_80074A40[];
extern s8 D_80074C08[];
extern s8 D_80074C40[];

void func_8003E414(u8* o) {
    s8 idx;
    s32 tbl;
    s8 lim;

    if (*(u8*)(o + 0x92) != 0) {
        return;
    }
    *(s8*)(o + 0x96) = -1;
    func_8003F608();
    func_8003F70C(o);
    idx = *(s8*)(o + 0x96);
    if (idx == -1) {
        return;
    }
    if (*(u8*)(o + 0xF7) != 0 || *(s8*)(o + 0xA6) != 0) {
        tbl = (s32)D_80074B98;
    } else {
        tbl = (s32)D_80074B60;
    }
    lim = *(s8*)(idx + tbl);
    if (idx == 0 && (*(s32*)(o + 0xFC) & 0x800)) {
        lim = 5;
    }
    if (*(s8*)(o + 0x98) >= lim) {
        return;
    }
    if (D_80074BD0[idx] != 0 && *(s8*)(o + 0x99) != 0) {
        return;
    }
    if (D_800749D8[idx] != 0 && *(s8*)(o + 0x99) != 0 &&
        *(s8*)(o + 0x97) == idx) {
        return;
    }
    if (*(s8*)(o + 0xA6) != 0 && (idx == 0xA || idx == 0xE)) {
        return;
    }
    ((void (*)(u8*))D_80074AA0[idx])(o);
    *(u8*)(o + 0x156) = 1;
    *(u8*)(o + 0x8E) = 1;
    *(u8*)(o + 0x8F) = 1;
    *(s8*)(o + 0x97) = idx;
    *(u8*)(o + 0x90) = 0;
    *(u8*)(o + 0x91) = D_80074A40[idx * 2];
    *(u8*)(o + 0x92) = (D_80074A40 + 1)[idx * 2];
    if ((*(s32*)(o + 0xFC) & 0x1000) && idx != 0xF) {
        if ((u32)(idx - 1) >= 7) {
            *(u8*)(o + 0x92) = (D_80074A40 + 1)[idx * 2] * 4;
        }
    }
    if (D_80074C08[idx] != 0) {
        *(s8*)(o + 0x98) += 1;
    }
    if (D_80074C40[idx] != 0) {
        *(s8*)(o + 0x99) += 1;
    }
    if (++*(s8*)(o + 0x9A) == 3) {
        *(s8*)(o + 0x9A) = 0;
    }
    func_8003F7F8(o, idx);
    if (*(s8*)(o + 0xF0) == 0 && *(s8*)(o + 0x93) == 0 &&
        *(s8*)(o + 0xA4) == 0) {
        if (idx == 0) {
            *(u8*)(o + 0xA2) = 6;
        }
        if (idx == 9) {
            *(u8*)(o + 0xA2) = 5;
        }
        if (idx == 0x12) {
            *(u8*)(o + 0xA2) = 7;
        }
        if (idx == 0x2D) {
            *(u8*)(o + 0xA2) = 6;
        }
        if (idx == 0x2E) {
            *(u8*)(o + 0xA2) = 7;
        }
    }
}
