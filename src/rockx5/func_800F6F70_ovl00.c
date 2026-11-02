#include "types.h"

extern void (*D_800FB4B0_ovl00[])(u8*);
extern u8 D_8009A11A;
extern u8 D_80074EE0[];
extern u8 D_800FB3E4_ovl00[];
extern u8 D_800FB3EC_ovl00[];
extern u8 D_800FB3F0_ovl00[];
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F6F70_ovl00(u8* obj) {
    s32 r;

    func_800317B8(obj);
    if (*(u8**)(obj + 0x54) == D_800FB3EC_ovl00) {
        if (obj[0x8A] != 0) {
            *(u8**)(obj + 0x58) = D_80074EE0;
        }
        r = func_80031DD0(obj);
        if (r == 0) {
            *(u8**)(obj + 0x50) = D_800FB3E4_ovl00;
            *(u8**)(obj + 0x54) = D_800FB3F0_ovl00;
            *(u8**)(obj + 0x58) = D_80074EE0;
            r = func_80031DD0(obj);
        }
    } else {
        r = func_80031DD0(obj);
    }
    if (r < 0) {
        obj[4] = 2;
        obj[5] = 0;
        obj[6] = 0;
        *(u16*)(obj + 0x42) &= 0x7FFF;
        D_8009A11A = 1;
        func_8002D9EC(obj, 0xFF, 0xFF);
        return;
    }
    if (r > 0 && r != 0x7F) {
        if ((u32)(r - 0x19) < 2) {
            obj[0x8A] = 2;
        } else {
            obj[0x8A] = 0x1E;
        }
        *(u8**)(obj + 0x58) = D_80074EE0;
        if (r == 8 || r == 0x11) {
            obj[5] = 0xA;
            obj[6] = 0;
            obj[0x8A] = 0xFF;
        }
    }
    if (obj[0x8A] != 0) {
        if (obj[0x8A]-- & 2) {
            *(u16*)(obj + 0x42) |= 0x8000;
        } else {
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
        if (obj[0x8A] == 0) {
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
    }
    D_800FB4B0_ovl00[(s8)obj[5]](obj);
}
