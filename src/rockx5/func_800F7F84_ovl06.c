#include "types.h"

extern void func_8002D9EC();
extern int func_8002D6FC();
extern u8 D_800D1C00[];
extern D_8009A1F8_t D_8009A1F8;

#define G (*(u8**)0x1F80004C)

void func_800F7F84_ovl06(u8* arg0) {
    signed char* p;

    arg0[3] = 0;
    p = *(signed char**)(G + 0x80);
    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--*(s16*)(arg0 + 0x7E) == -1) {
                *(s16*)(arg0 + 0x7E) = 5;
                *(u16*)(arg0 + 0x42) ^= 0x8000;
            }
            func_8002D9EC(arg0, 0x60, 0x60);
        }
    } else {
        D_8009A1F8.unk2A = D_8009A1F8.unkE;
        D_800D1C00[0x24] = 0;
        *(s32*)(D_800D1C00 + 0x20) = 0;
        if (*(signed char*)(D_800D1C00 + 0xC) != 12) {
            *(signed char*)(D_800D1C00 + 0xF) = 0x10;
        } else {
            *(signed char*)(D_800D1C00 + 0xF) = -0x80;
            D_800D1C00[*(signed char*)(D_800D1C00 + 0x1D) + 0x2C] = 1;
            D_800D1C00[0x1D] += 9;
        }
        func_8002D6FC(arg0);
    }
}
