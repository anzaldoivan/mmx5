#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800F6A8C_ovl28(u8* obj);

void func_800F6644_ovl28(u8* obj) {
    D_1F80004C.bytes[0x8C] = 0;
    func_800F6A8C_ovl28(obj);
    animate_object(obj);
    set_animation(obj, 1);
    obj[6]++;
}
