#include "types.h"

extern u8* func_8002D144(void);
extern u8* func_8002D27C(void);
extern s8 D_800D1C00[];

void func_80020950(void) {
    s8* p = D_800D1C00;
    u8* o;

    if (p[0xC] == 5 && p[0x1D] == 0) {
        p[0x1E] = 1;
        return;
    }
    if (p[0xC] == 0xC && p[0xD] != 0 && p[0x1D] == 0) {
        p[0x1E] = -2;
        if (D_800D1C00[0x44] != 0) {
            o = func_8002D27C();
            if (o != 0) {
                o[0] = 0x41;
                o[1] = 0x34;
                o[2] = 1;
            }
        }
    } else if (p[0x1E] == 0) {
        o = func_8002D144();
        if (o != 0) {
            o[0] = 1;
            o[1] = 0x1B;
        } else {
            p[0x1E] = 1;
        }
    }
}
