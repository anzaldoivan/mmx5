#include "types.h"
#include "addr.h"

extern s32 func_80028B18(s32, s32, s32, void*);
extern s8 D_8009A298;
extern s8 D_800D1C00[];
extern u8 D_800FDABC_ovl27[];

void func_800FA12C_ovl27(u8* arg0) {
    s8* p;

    func_80028B18(1, 0x12A0, 0x20, D_800FDABC_ovl27);
    p = D_800D1C00;
    D_8009A298 = 1;
    D_1F80004C.bytes[0x84] = p[0xA2] / 4;
    D_1F80004C.bytes[0x85] = p[0xA2] / 4;
    D_1F80004C.bytes[0x86] = p[0xA2] / 4;
    D_1F80004C.bytes[0x87] = p[0xA2] / 4;
    arg0[5] = 3;
    arg0[6] = 0;
}
