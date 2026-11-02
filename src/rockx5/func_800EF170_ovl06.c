#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002E804(u8*, u8*);
extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];
extern u8 D_800D1DC0[];
extern u8 D_800FDE88_ovl06[];

void func_800EF170_ovl06(u8* obj) {
    u8* g;
    u8* h;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        *(u8**)(obj + 0x68) = D_800FDE88_ovl06;
        obj[0x8C] = 0;
        func_800171E8(obj, 0x11);
        return;
    }
    if (!(obj[0xA8] & 8)) {
        obj[5] = 0xC;
        obj[6] = 0;
        return;
    }
    g = D_8009A0A0;
    if (((s8*)g)[0xD0] != 0) {
        return;
    }
    h = D_800D1C00;
    if (((s8*)h)[0xF] != 0) {
        return;
    }
    if (((s8*)g)[2] != 0 && ((s8*)g)[0x8E] != 0) {
        return;
    }
    if (((s8*)g)[0x7A] != 0 || ((s8*)g)[0xF3] != 0) {
        return;
    }
    if (*(u16*)(obj + 0x96) & 0x8200) {
        return;
    }
    if (func_8002E804(g, obj) == 0) {
        return;
    }
    if (((s8*)h)[0xF] != 0 || ((s8*)g)[0x5C] <= 0 || ((s8*)g)[0xA4] != 0 ||
        ((s8*)g)[0x79] != 0) {
        return;
    }
    obj[5] = 0xA;
    obj[6] = 0;
    func_800171E8(obj, 0x12);
    obj[0x97] |= 0x40;
    g[0xD5] = (obj == D_800D1DC0) ? 1 : 2;
}
