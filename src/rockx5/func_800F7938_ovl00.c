#include "types.h"

extern s32 func_8002DF78(void);
extern void func_8002E0F8(s32* a0, s32* a1, u8 a2);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_80074E40[];
extern u8 D_800FB598_ovl00[];
extern u8 D_800FB59C_ovl00[];
extern u8 D_800FB5A0_ovl00[];
extern u8 D_800FB640_ovl00[];

void func_800F7938_ovl00(u8* obj) {
    u8* p;
    s32 t;
    s32 v;
    s32 w;
    s16 m;

    p = *(u8**)(obj + 0x7C);
    *(u16*)(obj + 0x40) = *(u16*)(p + 0x40);
    w = *(u16*)(p + 0x42) & 0x7FFF;
    *(u16*)(obj + 0x42) = w;
    *(u8**)(obj + 0x30) = D_800FB640_ovl00;
    t = *(s32*)(p + 0x3C);
    v = 0x10;
    obj[0x16] = v;
    v = (s32)D_800FB598_ovl00;
    w = (s32)D_800FB59C_ovl00;
    *(s32*)(obj + 0x68) = v;
    *(s32*)(obj + 0x50) = w;
    obj[0x14] = 0;
    obj[0x15] = 0;
    obj[0x67] = 0;
    obj[3] = 1;
    *(u8**)(obj + 0x54) = D_800FB5A0_ovl00;
    *(u8**)(obj + 0x58) = D_80074E40;
    *(s32*)(obj + 0x3C) = t;
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA) - 0x30;
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE) + 0x28;
    func_8002E0F8((s32*)(obj + 0x20), (s32*)(obj + 0x24),
                  func_8002DF78() % 6 + 11);
    m = func_8002DF78() % 5 - 2;
    *(s32*)(obj + 0x20) *= m + 4;
    *(s32*)(obj + 0x24) *= m + 4;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x5C] = 1;
    obj[0x60] = 4;
    func_800171E8(obj, 0);
    obj[4]++;
}
