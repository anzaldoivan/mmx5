#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800D1C00[];

void func_800F5520_ovl28(u8* obj) {
    s8 state;
    u8* d;

    animate_object(obj);
    state = ((s8*)obj)[7];
    if (state == 1) {
        d = D_800D1C00;
        func_8002385C(0x42, 0xFF, d[0x2E]);
        d[0x2E] = state;
        obj[6]++;
    }
}
