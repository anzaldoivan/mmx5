#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C00[];
extern s16 D_800F5724_ovl20[][2];

void func_800F3DC8_ovl20(u8* a0) {
    *(s16*)(a0 + 0xA) = D_800F5724_ovl20[D_800D1C00[0x32]][0];
    *(s16*)(a0 + 0xE) = D_800F5724_ovl20[D_800D1C00[0x32]][1];
    func_8002D89C(a0);
}
