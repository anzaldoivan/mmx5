#include "types.h"
#include "addr.h"

extern u8 D_800D1C00[];
extern u8* D_8007755C[][2];
extern u8* D_800EF330_ovl23[];
extern u16 D_80091D58;

void func_800288B4(s32);

void func_800287F0(void) {
    u8* p = D_800D1C00;
    u8* src;
    u8* dst;
    u32 i;

    if ((s8)p[0xC] == 11) {
        src = D_800EF330_ovl23[(s8)p[0x1D]];
    } else {
        src = D_8007755C[(s8)p[0xC]][(s8)p[0xD]];
    }
    dst = D_1F800004;
    for (i = 0; i < D_80091D58 * 3; i++) {
        *dst++ = *src++;
    }
    func_800288B4(-1);
}
