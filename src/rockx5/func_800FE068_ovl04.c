#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void (*D_80102BA0_ovl04[])(u8*);

void func_800FE068_ovl04(u8* obj) {
    u8* child;

    child = *(u8**)(obj + 0x80);
    *(u16*)(obj + 0x42) &= 0x7FFF;
    if (obj[0x45] & 1) {
        obj[3] = 1;
    } else {
        obj[3] = 0;
    }
    if (((s8*)child)[5] >= 4) {
        obj[5]++;
        func_800171E8(obj, 0xB);
    }
    D_80102BA0_ovl04[((s8*)obj)[6]](obj);
}
