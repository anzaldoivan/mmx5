#include "types.h"

extern void func_8002D89C(u8*);
extern u8 D_8009A427;

void func_8004D1F4(u8* a0) {
    if (*(s8*)(a0 + 7) == D_8009A427) {
        *(s16*)(a0 + 0x42) = 0x7803;
    } else {
        *(s16*)(a0 + 0x42) = 0x7800;
    }
    func_8002D89C(a0);
}
