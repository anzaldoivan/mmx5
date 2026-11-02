#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);
extern s32 func_8002E024(void*, void*);
extern u8 D_80074E40[];
extern u8 D_8009A0A0[];
extern u8 D_800FB58C_ovl00[];
extern u8 D_800FB590_ovl00[];
extern u8 D_800FB594_ovl00[];
extern u8 D_800FB63C_ovl00[];

void func_800F7620_ovl00(u8* obj) {
    u8* p;
    s32 t;
    s32 v;
    s32 w;
    s32 r;

    p = *(u8**)(obj + 0x7C);
    *(u16*)(obj + 0x40) = *(u16*)(p + 0x40);
    w = *(u16*)(p + 0x42) & 0x7FFF;
    *(u16*)(obj + 0x42) = w;
    *(u8**)(obj + 0x30) = D_800FB63C_ovl00;
    t = *(s32*)(p + 0x3C);
    v = 0x10;
    obj[0x16] = v;
    v = (s32)D_800FB58C_ovl00;
    w = (s32)D_800FB590_ovl00;
    *(s32*)(obj + 0x68) = v;
    *(s32*)(obj + 0x50) = w;
    obj[0x14] = 0;
    obj[0x15] = 0;
    obj[0x67] = 0;
    obj[3] = 1;
    *(u8**)(obj + 0x54) = D_800FB594_ovl00;
    *(u8**)(obj + 0x58) = D_80074E40;
    *(s32*)(obj + 0x3C) = t;
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA) - 0x30;
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE) - 2;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x5C] = 1;
    obj[0x60] = 4;
    obj[0x8C] = func_8002E024(obj, D_8009A0A0);
    r = func_8002DF78() % 5 - 2;
    *(u16*)(obj + 0x8E) = 0x400;
    *(u16*)(obj + 0x90) = 0x20;
    obj[0x8C] = (obj[0x8C] + r) & 0x1F;
    if (((s8*)obj)[2] != 0) {
        *(u16*)(obj + 0x90) = 0x18;
    }
    func_800171E8(obj, 0);
    obj[5] = 0;
    obj[4]++;
}
