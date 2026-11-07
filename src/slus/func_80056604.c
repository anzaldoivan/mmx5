#include "types.h"
#include "addr.h"

extern u8 D_800C9310;

void func_80056604(u8* obj) {
    s32* src;
    s32* dst;
    u32 n;
    u8* rec;
    u8* cur;
    s8 step;

    if ((s8)--obj[0x21] == -1) {
        rec = *(u8**)(obj + 0x1C) + 2;
        *(u8**)(obj + 0x1C) = rec;
        step = ((s8*)rec)[1];
        if (step == 0) {
            obj[4]++;
            return;
        }
        if (step < 0) {
            *(u8**)(obj + 0x1C) = rec + step * 2;
        }
        cur = *(u8**)(obj + 0x1C);
        dst = *(s32**)(obj + 0x18);
        obj[0x21] = cur[1];
        *(u8**)(obj + 0x14) = D_1F800030 + (cur[0] << 5);
        src = *(s32**)(obj + 0x14);
        for (n = 0; n < ((s8*)obj)[0x20] * 8; n++) {
            *dst++ = *src++;
        }
        D_800C9310 |= 1;
    }
}
