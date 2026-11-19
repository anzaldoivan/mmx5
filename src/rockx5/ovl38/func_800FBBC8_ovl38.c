#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800D1C00[];

void func_800FBBC8_ovl38(u8* obj) {
    set_animation(obj, 1);
    func_8002385C(0x48, 0xFF, D_800D1C00[0x2E]);
    D_800D1C00[0x2E] = 1;
    obj[6]++;
}
