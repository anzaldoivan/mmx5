#include "types.h"

extern void func_8002D9EC();
extern int func_8002D6FC();
extern u8 D_800D1C00[];
extern D_8009A1F8_t D_8009A1F8;

#define G (*(u8**)0x1F80004C)

void func_800F54A8_ovl11(u8* arg0) {
    signed char* p;
    u8* d;

    arg0[3] = 0;
    p = *(signed char**)(G + 0x84);
    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--*(s16*)(arg0 + 0x7E) == -1) {
                *(s16*)(arg0 + 0x7E) = 5;
                *(u16*)(arg0 + 0x42) ^= 0x8000;
            }
            func_8002D9EC(arg0, 0x60, 0x60);
        }
    } else {
        d = D_800D1C00;
        if (*(signed char*)(d + 0xC) != 12) {
            *(signed char*)(d + 0xF) = 0x10;
        } else {
            *(signed char*)(d + 0xF) = -0x80;
            d[*(signed char*)(d + 0x1D) + 0x2C] = 1;
            d[0x1D] += 9;
        }
        D_8009A1F8.unk2A = D_8009A1F8.unkE;
        D_800D1C00[0x24] = 0;
        *(s32*)(D_800D1C00 + 0x20) = 0;
        func_8002D6FC(arg0);
    }
}
