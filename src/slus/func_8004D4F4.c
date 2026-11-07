#include "types.h"

extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);

void func_8004D4F4(u8 n, u8* src, u8* parent) {
    u8* o;
    s8 c;
    u8 b;

    while (n != 0) {
        o = func_8002D27C();
        if (o != 0) {
            o[0] = 0x41;
            c = *(s8*)parent;
            if (c == 0x61) {
                o[0] = c;
            }
            o[1] = 3;
            o[2] = 0;
            o[0x15] = func_8002DF78() & 0x40;
            o[4] = 0;
            o[5] = 0;
            o[6] = 0;
            *(s32*)(o + 8) =
                *(s32*)(parent + 8) + ((func_8002DF78() & 3) << 16);
            *(s32*)(o + 0xC) =
                *(s32*)(parent + 0xC) + ((func_8002DF78() & 3) << 16);
            b = *src++;
            *(u8**)(o + 0x54) = parent;
            o[0x58] = b;
        }
        n--;
    }
}
