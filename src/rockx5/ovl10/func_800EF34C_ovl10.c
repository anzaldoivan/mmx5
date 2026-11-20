#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 func_800EF450_ovl10(u8* arg);
extern s32 func_800EF494_ovl10(u8* arg);

void func_800EF34C_ovl10(u8* obj, u8* arg) {
    if (func_800EF450_ovl10(arg)) {
        animate_object(obj);
        obj[3] = 1;
    } else if (func_800EF494_ovl10(arg)) {
        set_animation(obj, 0x14);
        obj[3] = 1;
        obj[5] = 2;
    } else {
        obj[3] = 0;
        obj[5] = 0;
    }
}
