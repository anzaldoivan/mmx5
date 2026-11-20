#include "types.h"
#include "mmx5/globals.h"

void func_800FB920_ovl27(u8* obj) {
    u8* q;
    u8* p = *(u8**)(obj + 0x50);

    if (((s8*)p)[3] == 0 ||
        (((s8*)obj)[2] < 4 ? --*(s16*)(obj + 0x54) : p[0x8A]) == 0) {
        obj[3] = 0;
        obj[4]++;
    } else {
        animate_object(obj);
        q = *(u8**)(obj + 0x50);
        *(u16*)(obj + 0xA) = *(u16*)(q + 0xA);
        *(u16*)(obj + 0xE) = *(u16*)(q + 0xE);
    }
}
