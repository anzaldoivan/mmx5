/* Shared body (DK-5), from the banked draft of func_800F3414_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_80074EE0[];
extern u8 D_80075E80[];
extern void (*D_800FA0F8_ovl03[])(u8*);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* obj) {
    s32 d;
    s32 r;
    u8 t;
    u8* p;
    u8* q;

    p = D_8009A0A0;
    if (*(signed char*)(p + 0xCA) == 0) {
        obj[0x8D] = func_800317B8(obj);
        if (obj[0x8D] != 0) {
            if (*(signed char*)(p + 0xCA) != 0) {
                obj[0x8D] = 0xFF;
            }
        }
    }
    d = *(signed char*)(obj + 0x5C);
    r = func_80031DD0(obj);
    d -= *(signed char*)(obj + 0x5C);
    if (r < 0) {
        obj[4] = 2;
        obj[5] = 0;
        obj[6] = 0;
        *(u16*)(obj + 0x42) &= 0x7FFF;
        q = D_8009A0A0;
        q[0x7A] = 1;
        func_8002D9EC(obj, 0x64, 0x64);
        return;
    }
    if (d >= 3 && (*(u32*)(obj + 4) & 0xFFFF00) == 0x20900) {
        obj[5] = 10;
        obj[6] = 0;
    }
    if (r > 0 && r != 0x7F) {
        if ((u32)(r - 0x19) < 2) {
            obj[0x90] = 2;
        } else {
            obj[0x90] = 0x1E;
        }
        *(u8**)(obj + 0x58) = D_80074EE0;
        if (r == 7 || r == 0x10 || r == 0x2B) {
            obj[5] = 10;
            obj[6] = 0;
        }
    }
    t = obj[0x90];
    if (t != 0) {
        obj[0x90] = t + 0xFF;
        if (t & 2) {
            *(u16*)(obj + 0x42) |= 0x8000;
        } else {
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
        if (obj[0x90] == 0) {
            *(u8**)(obj + 0x58) = D_80075E80;
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
    }
    D_800FA0F8_ovl03[*(signed char*)(obj + 5)](obj);
}
