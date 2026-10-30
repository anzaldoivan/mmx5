/* Shared body (DK-5), from the banked draft of func_800EE9A8_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern u8 D_80074EE0[];
extern u8 D_80076100[];
extern u8 D_8009A11A;
extern u8 D_800F1BC4_ovl12[];
extern u8 D_800F1BC8_ovl12[];
extern u8 D_800F1BCC_ovl12[];
extern u8 D_800F1BD0_ovl12[];
extern u8 D_800F1BD4_ovl12[];
extern u8 D_800F1BD8_ovl12[];
extern u8 D_800F1BDC_ovl12[];
extern void* D_800F2000_ovl12[];

void DEDUP_NAME(u8* o) {
    u8* p;
    u8* q;
    s32 r;
    u8 t;
    u8 d;
    u8 c;

    t = o[0x47];
    if ((u32)(t - 0x2D) < 11) {
        if (t == 0x34) {
            *(u8**)(o + 0x50) = D_800F1BCC_ovl12;
        } else {
            *(u8**)(o + 0x50) = D_800F1BC8_ovl12;
        }
    } else {
        *(u8**)(o + 0x50) = D_800F1BC4_ovl12;
    }
    func_800317B8(o);
    r = o[0x47];
    if ((u32)(r - 0x5A) < 4) {
        *(u8**)(o + 0x54) = D_800F1BDC_ovl12;
        q = D_80074EE0;
        *(u8**)(o + 0x58) = q;
        r = func_80031DD0(o);
        if (r == 0) {
            if (o[0x84] != 0) {
                *(u8**)(o + 0x58) = q;
            } else {
                *(u8**)(o + 0x58) = D_80076100;
            }
            p = D_800F1BD8_ovl12;
            goto store54; // !FAKE: goto kept for the matching branch layout
        }
        o[0x84] = 1;
    } else {
        if (*(s8*)(o + 5) == 9) {
            if (o[0x84] < 20) {
                o[0x84] = 40;
            }
            if (*(s8*)(o + 6) == 3 && o[0x84] < 50) {
                o[0x84] = 120;
            }
        } else {
            c = r - 0x2D;
            if (c < 11) {
                p = D_800F1BD4_ovl12;
            } else {
                p = D_800F1BD0_ovl12;
            }
        store54:
            *(u8**)(o + 0x54) = p;
        }
        r = func_80031DD0(o);
    }
    if (r < 0) {
        o[4] = 2;
        o[5] = 0;
        o[6] = 0;
        *(u16*)(o + 0x42) &= 0x7FFF;
        D_8009A11A = 1;
        func_8002D9EC(o, 100, 100);
        return;
    }
    if (r > 0 && r != 0x7F) {
        o[0x84] = ((u32)(r - 0x19) < 2) ? 2 : 30;
        *(u8**)(o + 0x58) = D_80074EE0;
        if (r == 9 || r == 0x12 || r == 0x2D) {
            o[5] = 9;
            o[6] = 0;
        }
    }
    d = o[0x84];
    if (d != 0) {
        o[0x84] = d + 0xFF;
        if (d & 2) {
            *(u16*)(o + 0x42) |= 0x8000;
        } else {
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
        if (o[0x84] == 0) {
            *(u8**)(o + 0x58) = D_80076100;
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
    }
    ((void (*)(u8*))D_800F2000_ovl12[*(s8*)(o + 5)])(o);
}
