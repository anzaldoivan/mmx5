#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void (*D_800FE6E4_ovl28[])(u8* obj);

void func_800F92EC_ovl28(u8* obj) {
    D_800FE6E4_ovl28[((s8*)obj)[6]](obj);
    if (D_8009A0AA > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x30, 0x30);
}
