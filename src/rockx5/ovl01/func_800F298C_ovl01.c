#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern s32 D_8009A0A8;

void func_800F298C_ovl01(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 3) != 0) {
        obj[0x15] = (*(s32*)(obj + 8) <= D_8009A0A8) << 6;
        D_1F80004C.bytes[0x80] = 30;
        obj[6]++;
        *(s32*)(D_1F80004C.bytes + 0x88) = *(s32*)(obj + 0xC);
    }
}
