#include "types.h"

extern s32 D_8009A0A8;
extern void func_8002DF54(u8* a0);

void func_800FD6F4_ovl39(u8* obj) {
    *(s32*)(obj + 0x8) = D_8009A0A8 + 0x140000;
    func_8002DF54(obj);
    if (*(s16*)(obj + 0xE) >= 0x770) {
        *(s16*)(obj + 0x82) = 0x5A;
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
    }
}
