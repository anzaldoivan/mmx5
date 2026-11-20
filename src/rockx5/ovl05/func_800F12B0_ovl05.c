#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

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
