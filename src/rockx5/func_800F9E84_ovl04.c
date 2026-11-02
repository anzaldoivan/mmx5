#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800D1C00[];
extern void* D_80102BD0_ovl04[];

void func_800F9E84_ovl04(u8* obj) {
    u8* parent;
    u8* g;
    s32 r;
    s8 k;
    s32 f;

    obj[0x8E] = obj[5];
    parent = *(u8**)(obj + 0x80);
    *(s16*)(obj + 0xA) = *(s16*)(parent + 0xA) + *(s16*)(obj + 0x88);
    *(s16*)(obj + 0xE) = *(s16*)(parent + 0xE) + *(s16*)(obj + 0x8A);
    ((void (*)(u8*))D_80102BD0_ovl04[(s8)obj[5]])(obj);
    func_800317B8(obj);
    r = func_80031DD0(obj);
    if (r < 0) {
        func_8004FD24(obj);
        obj[5] = 4;
        obj[3] = 0;
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x84) = 0;
        D_800D1C00[0x27] |= 1;
        k = obj[2];
        if (k == 5) {
            func_800171E8(obj, 8);
        } else if (k == 6) {
            func_800171E8(obj, 0x34);
        } else if (k == 7) {
            func_800171E8(obj, 0x35);
        } else if (k == 8) {
            func_800171E8(obj, 0x36);
        }
    } else if (r > 0) {
        D_800D1C00[0x27] |= 1;
    } else if (*(u16*)(parent + 0x42) & 0x8000) {
        *(u16*)(obj + 0x42) |= 0x8000;
    }
    g = D_800D1C00;
    f = g[0x2A];
    if ((f & obj[0x92]) || (f & 4)) {
        if ((s8)obj[5] != 6) {
            func_8004FD24(obj);
            *(s32*)(obj + 0x54) = 0;
            *(s32*)(obj + 0x50) = 0;
        }
        if (g[0x2A] & 4) {
            obj[4]++;
            return;
        }
        obj[5] = 6;
    }
    if (D_800D1C00[0x2A] & 8) {
        obj[4]++;
    }
}
