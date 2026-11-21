#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void (*D_800F53E0_ovl20[])(u8* obj);

void func_800F1FE8_ovl20(u8* obj) {
    animate_object(obj);
    D_800F53E0_ovl20[*(s8*)(obj + 5)](obj);
    func_8002D9EC(obj, 0x80, 0x20);
}

void func_800F2040_ovl20(u8* obj) {
    u8* parent = *(u8**)(obj + 0x50);

    *(u16*)(obj + 0xA) = *(u16*)(parent + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(parent + 0xE);
    obj[3] = parent[3];
    if (((s8*)parent)[4] >= 3) {
        clear_object_slot(obj);
    }
}

#define D_800EEBA0_ovl00 func_800F20A4_ovl20
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
