#include "types.h"
#include "mmx5/globals.h"

void func_800FBB10_ovl38(u8* obj) {
    if (*(s8*)(obj + 0x45) != 0) {
        *(s16*)(obj + 0x7C) = 0x1E;
        *(s32*)(obj + 0x24) = -0x8000;
        obj[6]++;
    }
    animate_object(obj);
}
