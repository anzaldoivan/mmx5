#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_800F6A8C_ovl28(u8* obj);

void func_800F5DE4_ovl28(u8* obj) {
    func_800F6A8C_ovl28(obj);
    animate_object(obj);
    if (((s8*)obj)[7] == 2) {
        obj[7] = 3;
        set_animation(obj, 7);
        obj[6]++;
    }
}
