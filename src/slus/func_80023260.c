#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_80023260(u8* obj, u8* other) {
    s8 side = ((s8*)obj)[2];
    s32 want = (side == 0) ? 2 : 1;

    if (((s8*)other)[0x9B] == want || ((s8*)other)[0x9C] == want) {
        obj[3] = 1;
        func_800171E8(obj, side + 8);
        obj[4]++;
    }
}
