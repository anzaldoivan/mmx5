#include "types.h"

extern void (*D_800FA3A4_ovl29[])(u8*);
extern u8 D_8009A11A;
extern u8 D_80074EE0[];
extern u8 D_80075A20[];
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8002FB58(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F3EB8_ovl29(u8* obj) {
    s32 r;

    r = func_80031DD0(obj);
    if (r < 0) {
        obj[4] = 2;
        obj[5] = 0;
        obj[6] = 0;
        *(u16*)(obj + 0x42) &= 0x7FFF;
        D_8009A11A = 1;
        func_8002D9EC(obj, 0x40, 0x40);
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
            obj[5] = 0xE;
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
            *(u8**)(obj + 0x58) = D_80075A20;
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
    }
    D_800FA3A4_ovl29[(s8)obj[5]](obj);
    func_8002FB58(obj);
    func_800317B8(obj);
}
