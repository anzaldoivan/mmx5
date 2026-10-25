#include "types.h"
#include "addr.h"

extern void func_8002D89C(u8*);

void func_8004D3DC(u8* a0) {
    u8* base = D_801F3000;

    *(s16*)(a0 + 0x40) = 0x1F00;
    *(u8**)(a0 + 0x3C) = base + *(s32*)base;
    *(s8*)(a0 + 0x14) = -1;
    *(u8*)(a0 + 0x15) = 0;
    if (*(s16*)(a0 + 0xE) == 0x10) {
        *(s16*)(a0 + 0x42) = 0x7802;
    } else {
        *(s16*)(a0 + 0x42) = 0x7800;
    }
    *(s16*)(a0 + 0xA) = 0xA0;
    *(u8*)(a0 + 0x16) = 0;
    *(u8*)(a0 + 0x47) = *(u8*)(a0 + 2);
    *(u8*)(a0 + 4) += 1;
    func_8002D89C(a0);
}
