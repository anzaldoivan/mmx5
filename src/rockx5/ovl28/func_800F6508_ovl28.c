#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800F6A8C_ovl28(u8* obj);

void func_800F6508_ovl28(u8* obj) {
    func_800F6A8C_ovl28(obj);
    animate_object(obj);
    if (((s8*)obj)[7] == 2) {
        obj[7] = 3;
        D_1F80004C.bytes[0x8C] = 0;
        *(s16*)(obj + 0x7C) = 0x1E;
        *(s16*)(obj + 0x7E) = 5;
        set_animation(obj, 9);
        obj[6]++;
    }
}
