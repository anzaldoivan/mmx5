/* Shared body (DK-5), from the banked draft of func_800F7640_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* func_8002C938();
extern void func_8003D29C(s32, s32);
extern u8 D_8009A1F8[];
extern s8 D_800D1C0F;

void DEDUP_NAME(u8* arg0) {
    u8* p;
    u8* b;
    s32 i;

    if (D_800D1C0F == 0) {
        if (*(s16*)(arg0 + 0x7C) == 0x28) {
            b = D_8009A1F8;
            *(s32*)(arg0 + 0x94) = *(s16*)(b + 0x26);
            *(s16*)(b + 0x26) = *(u16*)(b + 0x24) - 0x10;
        }
        *(s16*)(arg0 + 0x7C) = *(u16*)(arg0 + 0x7C) - 1;
        if (*(s16*)(arg0 + 0x7C) == 0) {
            func_8003D29C(0x14, 0x40);
        }
        if (**(s8**)(arg0 + 0x80) == 0) {
            arg0[7] = 0;
            for (i = 0; i < 25; i++) {
                p = func_8002C938();
                if (p != 0) {
                    p[0] = 0x61;
                    p[1] = 0x39;
                    p[2] = 1;
                    *(u8**)(p + 0x80) = arg0;
                }
            }
            *(s16*)(arg0 + 0x7C) = 0x78;
            arg0[6]++;
        }
    }
}
