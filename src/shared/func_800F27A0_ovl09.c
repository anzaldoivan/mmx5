/* Shared body (DK-5), from the banked draft of func_800F27A0_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800FADA0_ovl09[])(u8*);
extern u8 D_8009A11A;
extern u8 D_80074EE0[];
extern u8 D_80075DE0[];
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* obj) {
    s32 r;

    obj[0x93] = func_800317B8(obj);
    r = func_80031DD0(obj);
    if (r < 0) {
        obj[4] = 2;
        obj[5] = 0;
        obj[6] = 0;
        *(u16*)(obj + 0x42) &= 0x7FFF;
        D_8009A11A = 1;
        func_8002D9EC(obj, 0x64, 0x64);
        return;
    }
    if (r > 0 && r != 0x7F) {
        if ((u32)(r - 0x19) < 2) {
            obj[0x94] = 2;
        } else {
            obj[0x94] = 0x1E;
        }
        *(u8**)(obj + 0x58) = D_80074EE0;
        if (r == 6 || r == 0xF || r == 0x25 || r == 0x40) {
            obj[5] = 0xB;
            obj[6] = 0;
        }
    }
    if (obj[0x94] != 0) {
        if (obj[0x94]-- & 2) {
            *(u16*)(obj + 0x42) |= 0x8000;
        } else {
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
        if (obj[0x94] == 0) {
            *(u8**)(obj + 0x58) = D_80075DE0;
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
    }
    D_800FADA0_ovl09[(s8)obj[5]](obj);
}
