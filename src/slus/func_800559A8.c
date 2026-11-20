#include "types.h"
#include "mmx5/graphics.h"

extern u8 D_80091C44;

void func_800559A8(u8* obj) {
    if (D_80091C44 == 1) {
        set_animation(obj, 0xB);
        obj[6] = 0;
        obj[5]++;
    }
}
