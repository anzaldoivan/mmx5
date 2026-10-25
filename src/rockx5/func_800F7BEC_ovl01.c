#include "types.h"

extern int func_8002D6FC();
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_800F79C0_ovl01(u8* a0);
extern s16
    D_800FD408_ovl01[][3]; /* 6-byte rows: [1], [2] passed to func_8002D938 */
extern u8 D_8009A197;

void func_800F7BEC_ovl01(u8* a0) {
    if (*(*(u8**)(a0 + 0x20) + 0x87) >= 2) {
        func_8002D6FC(a0);
    } else {
        if (func_8002D938(a0, D_800FD408_ovl01[*(s8*)(a0 + 2)][1],
                          D_800FD408_ovl01[*(s8*)(a0 + 2)][2]) == 0 &&
            D_8009A197 == 0 && !(*(u16*)(*(u8**)(a0 + 0x20) + 0x42) & 0x8000)) {
            func_800F79C0_ovl01(a0);
        }
    }
}
