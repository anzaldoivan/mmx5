#include "types.h"
#include "mmx5/globals.h"

extern u16 D_800FED48_ovl39[];

void func_800FE6E8_ovl39(u8* obj) {
    u8* parent = *(u8**)(obj + 0x50);

    *(u16*)(obj + 0xA) =
        *(u16*)(parent + 0xA) + D_800FED48_ovl39[*(s8*)(obj + 2) - 3];
    *(u16*)(obj + 0xE) = *(u16*)(parent + 0xE) + 0x70;
    animate_object(obj);
    if (*(s8*)(parent + 6) >= 10 || *(s8*)(parent + 4) == 2) {
        obj[4]++;
    }
}
