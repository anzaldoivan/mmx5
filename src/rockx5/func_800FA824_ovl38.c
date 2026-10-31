#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_800FD580_ovl38[];
extern u8 D_800FD584_ovl38[];
extern u8 D_800FD588_ovl38[];

void func_800FA824_ovl38(u8* obj) {
    s32 v;

    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) = *(s16*)(obj + 0x7C) - 1;
        return;
    }
    func_800171E8(obj, 6);
    *(u8**)(obj + 0x50) = D_800FD580_ovl38;
    *(u8**)(obj + 0x54) = D_800FD584_ovl38;
    *(u8**)(obj + 0x68) = D_800FD588_ovl38;
    if (*(s16*)(obj + 0xA) >= 0x1211) {
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = rcos(0x864) * 16;
        *(s32*)(obj + 0x24) = rsin(0x864) * 16;
    } else {
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x20) = rcos(0xF9C) * 16;
        *(s32*)(obj + 0x24) = rsin(0xF9C) * 16;
    }
    v = *(s32*)(obj + 0x20);
    if (v != 0) {
        *(s32*)(obj + 0x20) = v * 11 / 2;
    } else {
        *(s32*)(obj + 0x20) = 0;
    }
    v = *(s32*)(obj + 0x24);
    if (v != 0) {
        *(s32*)(obj + 0x24) = v * 11 / 2;
    } else {
        *(s32*)(obj + 0x24) = 0;
    }
    *(s16*)(obj + 0x7C) = 8;
    obj[6]++;
}
