/* W84 draft: copy state byte, follow parent, dispatch state handler, resolve hit (rockx5 ovl04). */
#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern u8 D_800D1C00[];
extern void* D_80102D34_ovl04[];

void func_800FCC84_ovl04(u8* obj) {
    u8* parent;
    s32 r;
    u8 st;

    st = obj[5];
    parent = *(u8**)(obj + 0x80);
    obj[0x8E] = st;
    *(s16*)(obj + 0xA) = *(s16*)(parent + 0xA) + *(s16*)(obj + 0x88);
    *(s16*)(obj + 0xE) = *(s16*)(parent + 0xE) + *(s16*)(obj + 0x8A);
    ((void (*)(u8*))D_80102D34_ovl04[(s8)st])(obj);
    if (D_800D1C00[0x26] & 2) {
        r = func_80031DD0(obj);
        if (r < 0) {
            func_8004FD24(obj);
            obj[5] = 3;
            obj[3] = 0;
            *(s32*)(obj + 0x54) = 0;
            *(s32*)(obj + 0x84) = 0;
            D_800D1C00[0x27] |= 1;
            D_800D1C00[0x2A] |= 1;
        } else if (r > 0) {
            D_800D1C00[0x27] |= 1;
        } else if (*(u16*)(parent + 0x42) & 0x8000) {
            *(u16*)(obj + 0x42) |= 0x8000;
        }
    }
    if (D_800D1C00[0x2A] & 4) {
        obj[4]++;
    }
}
