#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_800FD574_ovl38[];
extern u8 D_800FD578_ovl38[];
extern u8 D_800FD57C_ovl38[];

void func_800FBE60_ovl38(u8* arg0) {
    set_animation(arg0, 3);
    *(u8**)(arg0 + 0x50) = D_800FD574_ovl38;
    *(u8**)(arg0 + 0x54) = D_800FD578_ovl38;
    *(u8**)(arg0 + 0x68) = D_800FD57C_ovl38;
    arg0[6]++;
}

extern void func_800FAC40_ovl38(void);
extern s16 D_8009A0AE;

void func_800FBEB8_ovl38(u8* a0) {
    u8* g = D_1F80004C.bytes;
    s16 x;
    s16 y;

    if (++*(s16*)(g + 0x84) >= 0x32) {
        func_800FAC40_ovl38();
        return;
    }
    x = *(s16*)(a0 + 0xE);
    y = D_8009A0AE;
    if (((x - y) < 0 ? (y - x) : (x - y)) >= 0x30) {
        a0[5] = 5;
        a0[6] = 0;
    }
}
