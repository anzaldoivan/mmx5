/* Shared body (DK-5), from the banked draft of func_800F4CDC_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern s32 func_800317B8(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern void func_800F486C_ovl04(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern signed char D_800D1CA2;
extern u8 D_80075CA0[];
extern u8 D_8009A11A;
extern u8 D_80074EE0[];
extern void* D_80101C14_ovl04[];
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* p) {
    s32 r;
    s32 t;
    u8* g;

    if (*(s8*)(p + 0x5C) < (s8)(D_800D1CA2 / 3)) {
        if (*(s8*)(p + 5) != 4) {
            if (*(s8*)(p + 5) != 2) {
                p[6] = 0;
            }
            p[5] = 2;
        }
    }
    r = func_80031DD0(p);
    func_800317B8(p);
    t = p[0x8A];
    if (t != 0) {
        t--;
        p[0x8A] = t;
        if (t & 1) {
            *(u16*)(p + 0x42) |= 0x8000;
        } else {
            *(u16*)(p + 0x42) &= 0x7FFF;
        }
    } else {
        *(u8**)(p + 0x58) = D_80075CA0;
    }
    if (r < 0) {
        p[4]++;
        p[5] = 0;
        *(u16*)(p + 0x42) &= 0x7FFF;
        D_8009A11A = 1;
        return;
    }
    if (r > 0 && r != 0x7F) {
        if (r == 0x19 || r == 0x1A) {
            p[0x8A] = 2;
        } else {
            p[0x8A] = 0x1E;
        }
        *(u8**)(p + 0x58) = D_80074EE0;
        if (r == 2 || r == 0xB || r == 0x21) {
            func_800171E8(p, 6);
            p[0x8D] = 0x3C;
            p[4] = 3;
            p[7] = 0;
            return;
        }
    }
    ((void (*)(u8*))D_80101C14_ovl04[*(s8*)(p + 5)])(p);
    g = D_8009A0A0;
    if (*(s8*)(g + 0xF3) == 0) {
        if (*(s8*)(p + 5) == 5) {
            func_800F486C_ovl04(p);
        }
    } else if (!(g[0xFA] == 2 || g[0xFA] == 3)) {
        if (*(s8*)(p + 5) == 5) {
            func_800F486C_ovl04(p);
        }
    }
    func_8002D9EC(p, 0x80, 0x80);
}
