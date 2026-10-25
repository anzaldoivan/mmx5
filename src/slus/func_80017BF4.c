#include "types.h"

extern void func_800177B0(s32, s32);
extern s8 D_800D1C00[];
extern u8 D_80070884[];

void func_80017BF4(void) {
    s32 a;

    if (D_800D1C00[0xC] == 0xC && D_800D1C00[0x1D] == 0x15) {
        a = 0x11;
        if (D_800D1C00[0x31] == 1) {
            a = 0x10;
        }
    } else {
        a = D_80070884[D_800D1C00[0xC] * 2];
    }
    func_800177B0(a, D_80070884[D_800D1C00[0xC] * 2 + 1]);
}
