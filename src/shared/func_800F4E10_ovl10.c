#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C00[];
extern s16 D_8009A1F8[];

void func_800F4E10_ovl10(Obj* obj) {
    if (D_800D1C00[0xF] != 0) {
        return;
    }
    if (obj->timer == 0x122) {
        if (D_800D1C00[0xC] != 0xC) {
            D_8009A1F8[0x13] = 0x1F70;
            D_8009A1F8[0x12] = 0x1F70;
        } else {
            D_8009A1F8[0x13] = 0xA70;
            D_8009A1F8[0x12] = 0xA70;
        }
    }
    if (D_800D1C00[0xC] != 0xC && obj->timer == 0x104) {
        func_8003D29C(0x14, 0x40);
    }
    if (--obj->timer == 0) {
        obj->timer = 0xF0;
        obj->step = 2;
    }
}
