#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8 D_800D1C00[];
extern u16 D_800F596C_ovl20[][2];

void func_800F4908_ovl20(u8* a0) {
    u8* p = D_800D1C00;

    if (((s8*)p)[0x30] != 0) {
        clear_object_slot();
    } else {
        *(u16*)(a0 + 0xA) = D_800F596C_ovl20[((s8*)p)[0x31]][0];
        *(u16*)(a0 + 0xE) = D_800F596C_ovl20[((s8*)p)[0x31]][1] + 5;
        func_8002D9EC(a0, 0x80, 0x40);
    }
}
