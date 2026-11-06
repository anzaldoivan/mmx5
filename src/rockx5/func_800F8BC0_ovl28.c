#include "types.h"
#include "addr.h"

extern u8* func_8002C938();
extern s32 func_8002B5B4(s32);
extern void func_8002D720(u8* arg0);
extern s8 D_8009A0A2;
extern u8 D_800D1CCB;

void func_800F8BC0_ovl28(u8* arg0) {
    u8* p;
    s32 x;
    s32 y;

    if (D_8009A0A2 == 0) {
        p = func_8002C938();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x41;
            x = func_8002B5B4(0x41);
            y = func_8002B5B4(0x41);
            *(s16*)(p + 0x42) =
                ((x * 4 + 0x18) % 16) | (((y + 6) / 4 + 0x1E0) << 6);
            *(s32*)(p + 0x3C) =
                (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x41)];
            if (D_800D1CCB & 0x80) {
                p[2] = 0;
            } else {
                p[2] = 1;
            }
        }
    }
    func_8002D720(arg0);
}
