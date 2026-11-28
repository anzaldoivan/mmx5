#include "types.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

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
        D_800C9310.b |= 1;
    }
}

#define D_800EEBA0_ovl00 func_800566E8
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
