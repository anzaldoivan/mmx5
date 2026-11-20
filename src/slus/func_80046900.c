#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s8 D_8009A0A5;

void func_80046900(u8* obj) {
    u8* p = *(u8**)(obj + 0x50);

    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    animate_object(obj);
    if (*(s8*)p == 0 || *(s8*)(p + 4) >= 2 || D_8009A0A5 == 20) {
        clear_object_slot(obj);
    }
}
