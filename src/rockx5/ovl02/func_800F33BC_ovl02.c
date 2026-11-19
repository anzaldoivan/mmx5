#include "types.h"
#include "mmx5/globals.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_800F33BC_ovl02(u8* obj) {
    animate_object(obj);
    *(s16*)(obj + 0x7C) += 1;
    if (*(s16*)(obj + 0x7C) >= 0x1F) {
        obj[3] = 0;
        obj[4]++;
    } else if (D_8009A420_as_s32 & 1) {
        obj[3] = 0;
    } else {
        func_8002D9EC(obj, 0x20, 0x20);
    }
}
