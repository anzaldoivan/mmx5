#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A0A0[];

void func_800F2A34_ovl04(u8* arg0) {
    u8* p;

    D_1F80004C.bytes[0x84] = 0;
    p = D_8009A0A0;
    *(s16*)(p + 0xA) = *(s16*)(arg0 + 0xA);
    *(s16*)(p + 0xE) = *(s16*)(arg0 + 0xE);
    p[3] = 0;
    func_800171E8(arg0, 3);
    *(s16*)(arg0 + 0x7C) = 0x78;
    arg0[6]++;
}
