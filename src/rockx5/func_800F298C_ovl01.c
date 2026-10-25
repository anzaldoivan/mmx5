#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern s32 D_8009A0A8;

void func_800F298C_ovl01(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 3) != 0) {
        obj[0x15] = (*(s32*)(obj + 8) <= D_8009A0A8) << 6;
        D_1F80004C.bytes[0x80] = 30;
        obj[6]++;
        *(s32*)(D_1F80004C.bytes + 0x88) = *(s32*)(obj + 0xC);
    }
}
