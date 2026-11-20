#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern void func_800EF550_ovl27(u8*);
extern s8 D_800D1C00[];
extern Blk200 D_800FDD58_ovl27;
extern Blk80 D_800FDC18_ovl27;
extern Blk20 D_800FDD18_ovl27;
extern Blk20 D_800FE158_ovl27;

void func_800EEE24_ovl27(u8* arg0) {
    u8* src;

    if (D_800D1C00[0x1D] >= 3) {
        arg0[5] = 1;
    } else {
        arg0[5] = 0;
    }
    D_800D1C00[0x2A] = 0;
    arg0[6] = 0;
    *(s16*)(arg0 + 0x14) = 0;
    *(s16*)(arg0 + 0x18) = 0;
    arg0[4]++;
    D_800FDD58_ovl27 = *(Blk200*)(D_1F800028 + 0xA00);
    *(s16*)(arg0 + 0x1A) = func_8002B5B4(0x3C) * 4 + 0x18;
    src = D_1F800028 + *(s16*)(arg0 + 0x1A) * 32;
    D_800FDC18_ovl27 = *(Blk80*)src;
    src = D_1F800028 + 0x8C0;
    D_800FDD18_ovl27 = *(Blk20*)src;
    src = D_1F800028 + 0x8A0;
    D_800FE158_ovl27 = *(Blk20*)src;
    func_800EF550_ovl27(arg0);
}
