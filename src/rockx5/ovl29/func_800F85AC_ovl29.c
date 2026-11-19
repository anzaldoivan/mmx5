#include "types.h"
#include "mmx5/globals.h"

void func_800F85AC_ovl29(u8* obj) {
    u8* src = *(u8**)(obj + 0x50);

    *(s32*)(obj + 0x8) = *(s32*)(src + 0x8);
    *(s32*)(obj + 0xC) = *(s32*)(src + 0xC);
    animate_object(obj);
    func_8002D89C(obj);
}
