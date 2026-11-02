#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern u8 D_800D1C00[];
extern void* D_80102D1C_ovl04[];

void func_800FCB44_ovl04(u8* obj) {
    s32 r;
    u8 st;
    u8* p;

    st = obj[5];
    p = *(u8**)(obj + 0x80);
    obj[0x8E] = st;
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA) + *(u16*)(obj + 0x88);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE) + *(u16*)(obj + 0x8A);
    ((void (*)(u8*))D_80102D1C_ovl04[(s8)st])(obj);
    r = func_80031DD0(obj);
    if (r < 0) {
        func_8004FD24(obj);
        obj[5] = 4;
        obj[3] = 0;
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x84) = 0;
        func_800171E8(obj, 0x1C);
        D_800D1C00[0x27] |= 1;
    } else if (r > 0) {
        D_800D1C00[0x27] |= 1;
    } else if (*(u16*)(p + 0x42) & 0x8000) {
        *(u16*)(obj + 0x42) |= 0x8000;
    }
    if (D_800D1C00[0x2A] & 0xC) {
        func_8004FD24(obj);
        obj[4]++;
    }
}
