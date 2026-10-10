#include "types.h"

#define SCR (*(u8**)0x1F80004C)

extern void (*D_80101C24_ovl07[])(u8*);
extern u8 D_8009A11A;
extern u8 D_80074EE0[];
extern u8 D_80075D40[];
extern void func_800FB3A4_ovl07(u8* a0);
extern void func_800FB5A4_ovl07(u8* a0);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);

void func_800F991C_ovl07(u8* obj) {
    s32 r;
    u8 t;
    u8* p;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    D_80101C24_ovl07[*(signed char*)(obj + 5)](obj);
    func_800FB3A4_ovl07(obj);
    func_800FB5A4_ovl07(obj);
    if (SCR[0x89] == 0) {
        return;
    }
    func_800317B8(obj);
    r = func_80031DD0(obj);
    if (r < 0) {
        D_8009A11A = 1;
        obj[4] = 2;
        obj[5] = 0;
        return;
    }
    if (r > 0 && r != 0x7F) {
        *(u8**)(obj + 0x58) = D_80074EE0;
        if ((u32)(r - 0x19) < 2) {
            SCR[0x88] = 2;
        } else {
            SCR[0x88] = 0x1E;
        }
        if (r == 4 || r == 0xD || r == 0x23) {
            obj[5] = 0xB;
            obj[6] = 0;
        }
    }
    p = SCR;
    t = p[0x88];
    if (t != 0) {
        p[0x88] = t + 0xFF;
        if (t & 2) {
            *(u16*)(obj + 0x42) |= 0x8000;
        } else {
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
        if (SCR[0x88] == 0) {
            *(u8**)(obj + 0x58) = D_80075D40;
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
    }
}
