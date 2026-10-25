#include "types.h"
#include "addr.h"

extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F12B0_ovl05(u8* a0) {
    u8 v;

    a0[3] = 0;
    v = (*(u8**)(D_1F80004C.bytes + 0x80))[0x91];
    switch (v) {
    case 0:
        a0[4] = 2;
        break;
    case 2:
        func_8002D9EC(a0, 0x40, 0x40);
        break;
    }
}
