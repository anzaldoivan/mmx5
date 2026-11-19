#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FA2E0_ovl29[][6];

void func_800F4DD4_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        obj[5] = D_800FA2E0_ovl29[obj[0x8D]][obj[0x8E]];
        obj[0x8E]++;
        obj[6] = 0;
        set_animation(obj, 0);
    }
    animate_object(obj);
}
