#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002E058(void*, s32);
extern s32 D_800FE458_ovl06;
extern s16 D_800FE45C_ovl06[];

void func_800F2D38_ovl06(u8* obj) {
    s16 dx;
    s32 anim;
    s8 kind;
    u8 flip;
    s32 j;

    obj[0x4] = 1;
    obj[0x3] = 1;
    obj[0x16] = 3;
    kind = obj[0x2];
    flip = obj[0x15];
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s32**)(obj + 0x50) = &D_800FE458_ovl06;
    j = kind * 2;
    dx = D_800FE45C_ovl06[j];
    if (flip != 0) {
        dx = -dx;
    }
    *(s16*)(obj + 0xA) += dx;
    *(s16*)(obj + 0xE) += D_800FE45C_ovl06[j + 1];
    if (kind == 0) {
        anim = (flip == 0) * 0x10;
    } else {
        anim = 0x1C;
        if (flip == 0) {
            anim = 0x14;
        }
    }
    func_8002E058(obj, anim);
    obj[0x5C] = 1;
    obj[0x60] = 3;
    *(s32*)(obj + 0x20) *= 8;
    *(s32*)(obj + 0x24) *= 8;
    func_800171E8(obj, (s8)obj[0x2] + 0x1F);
}
