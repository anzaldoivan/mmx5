#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800F53E0_ovl20[])(u8* obj);

void func_800F1FE8_ovl20(u8* obj) {
    animate_object(obj);
    D_800F53E0_ovl20[*(s8*)(obj + 5)](obj);
    func_8002D9EC(obj, 0x80, 0x20);
}
