#include "types.h"

extern void Ovl_Load(s32, s32);
extern D1C00_800F6A94 D_800D1C00;
extern s8 D_800D1C26[];

void func_800F6A94_ovl18(u8* arg0) {
    s32 i;

    for (i = 8; i < 16; i++) {
        if (D_800D1C00.f26[i] == 0) {
            break;
        }
    }
    if (i == 16) {
        for (i = 8; i < 16; i++) {
            D_800D1C26[i] = 0;
        }
    }
    if (D_800D1C00.f26[11] != 1) {
        D_800D1C00.f26[11] = 1;
        Ovl_Load(0x26, 0x800FA000);
        arg0[4]++;
    } else {
        arg0[4] += 2;
    }
}
