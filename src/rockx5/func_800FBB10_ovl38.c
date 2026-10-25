#include "types.h"

extern void func_80017248(u8* obj);

void func_800FBB10_ovl38(u8* obj) {
    if (*(s8*)(obj + 0x45) != 0) {
        *(s16*)(obj + 0x7C) = 0x1E;
        *(s32*)(obj + 0x24) = -0x8000;
        obj[6]++;
    }
    func_80017248(obj);
}
