#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 func_8002FB58(u8* obj);

void func_800F19DC_ovl09(u8* a0) {
    func_8002DF54(a0);
    func_8002FB58(a0);
    if (a0[0x70] & 4) {
        *(s32*)(a0 + 0x24) = 0;
        *(s32*)(a0 + 0x2C) = 0;
        *(s32*)(a0 + 0x20) = 0;
        *(s32*)(a0 + 0x28) = 0;
        a0[0x67] = 0;
        if (a0[0x15] == 0) {
            a0[0x8F] = 1;
            a0[0x5] = 2;
        } else {
            a0[0x8F] = 0;
            a0[0x5] = 3;
        }
        a0[0x6] = 0;
    }
}
