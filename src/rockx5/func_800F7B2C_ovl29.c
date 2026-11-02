#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern s32 func_8002DF78(void);
extern void func_8002D89C(u8*);
extern u32* D_80098118;
extern s32 D_800FA568_ovl29[];
extern s32 D_800FA588_ovl29[];
extern s16 D_800FA5A8_ovl29[];

void func_800F7B2C_ovl29(u8* a0) {
    s32 r0;
    s32 r1;

    a0[3] = 1;
    a0[0x47] = a0[0x54];
    *(s32*)(a0 + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x84)];
    *(u16*)(a0 + 0x40) = D_80098118[func_8002B5B4(0x84)] >> 7;
    r0 = func_8002B5B4(0x84);
    r1 = func_8002B5B4(0x84);
    *(u16*)(a0 + 0x42) = ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
    a0[0x16] = 1;
    if (((s8*)a0)[0x58] == 1) {
        *(s32*)(a0 + 0x2C) = 0x5000;
        *(s32*)(a0 + 0x20) += D_800FA568_ovl29[func_8002DF78() & 7];
        *(s32*)(a0 + 0x24) = D_800FA588_ovl29[func_8002DF78() & 7];
    } else {
        *(s32*)(a0 + 0x2C) = D_800FA5A8_ovl29[func_8002DF78() & 7];
    }
    a0[4]++;
    func_8002D89C(a0);
}
