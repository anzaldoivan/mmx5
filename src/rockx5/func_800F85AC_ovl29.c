#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D89C(u8* obj);

void func_800F85AC_ovl29(u8* obj) {
    u8* src = *(u8**)(obj + 0x50);

    *(s32*)(obj + 0x8) = *(s32*)(src + 0x8);
    *(s32*)(obj + 0xC) = *(s32*)(src + 0xC);
    func_80017248(obj);
    func_8002D89C(obj);
}
