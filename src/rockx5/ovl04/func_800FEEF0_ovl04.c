#include "types.h"
#include "mmx5/globals.h"
#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

void func_800FEEF0_ovl04(u8* a0) {
    if (D_800D1C28_as_u8 & a0[0x93]) {
        a0[0x95] = ~a0[0x93];
        a0[5]++;
    }
    func_8002D9EC(a0, 0x10, 0x10);
}
