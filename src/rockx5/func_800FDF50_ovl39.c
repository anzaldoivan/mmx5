#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);

void func_800FDF50_ovl39(u8* obj) {
    u8* p;

    func_80017248(obj);
    *(u16*)(obj + 0xA) =
        *(u16*)(*(u8**)(obj + 0x7C) + 0xA) + *(u16*)(obj + 0x90);
    func_800317B8(obj);
    p = *(u8**)(obj + 0x7C);
    if (*(s8*)(p + 4) == 2 || *(s8*)(p + 6) >= 10) {
        obj[5]++;
    }
}
