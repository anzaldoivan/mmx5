#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_800F2E90_ovl10(u8* a0);
extern u8 D_8009A0A0[];

void func_800F2D3C_ovl10(u8* obj) {
    u8* sub;
    u8* p;
    u8* q;

    sub = *(u8**)(obj + 0x7C);
    if (*(s8*)(sub + 0x45) == 1) {
        *(u8**)(obj + 0x50) = obj + 0x8C;
        *(u8**)(obj + 0x54) = obj + 0x8C;
        sub[0x80] = 0;
        obj[6]++;
        return;
    }
    obj[0x8C] = -sub[0x45];
    obj[0x8E] = sub[0x45] - 0x24;
    if (*(s8*)(sub + 0x45) == 3) {
        *(u8**)(obj + 0x50) = 0;
        *(u8**)(obj + 0x54) = 0;
    } else {
        *(u8**)(obj + 0x50) = obj + 0x8C;
        *(u8**)(obj + 0x54) = obj + 0x8C;
    }
    if (func_800F2E90_ovl10(obj) != 0) {
        obj[5] = 3;
        *(u8**)(obj + 0x50) = 0;
        *(u8**)(obj + 0x54) = 0;
        obj[6] = 0;
        p = D_8009A0A0;
        if (*(s8*)(p + 2) == 0) {
            func_800171E8(obj, 6);
        } else {
            func_800171E8(obj, 7);
        }
        q = D_8009A0A0;
        *(u16*)(obj + 0xA) = *(u16*)(q + 0xA);
    }
}
