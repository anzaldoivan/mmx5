#include "types.h"
#include "mmx5/globals.h"

void func_800FDF50_ovl39(u8* obj) {
    u8* p;

    animate_object(obj);
    *(u16*)(obj + 0xA) =
        *(u16*)(*(u8**)(obj + 0x7C) + 0xA) + *(u16*)(obj + 0x90);
    func_800317B8(obj);
    p = *(u8**)(obj + 0x7C);
    if (*(s8*)(p + 4) == 2 || *(s8*)(p + 6) >= 10) {
        obj[5]++;
    }
}
