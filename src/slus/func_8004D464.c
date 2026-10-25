#include "types.h"

extern void func_8002D89C(u8*);
extern u8 D_8009A427;

void func_8004D464(u8* a0) {
    s16 v;

    if (*(s16*)(a0 + 0xE) != 0x10) {
        v = 0x7800;
        if (*(s8*)(a0 + 7) == D_8009A427) {
            v = 0x7803;
        }
        *(s16*)(a0 + 0x42) = v;
    }
    func_8002D89C(a0);
}
