#include "types.h"
#include "mmx5/graphics.h"

extern void func_800F90AC_ovl09(u8* obj);

void func_800F8B0C_ovl09(u8* obj) {
    set_animation(obj, 0xC);
    func_800F90AC_ovl09(obj);
    obj[6]++;
}
