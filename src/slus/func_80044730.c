#include "types.h"

extern void func_8003A874(u8*);

s32 func_80044730(u8* arg0) {
    if (*(s8*)(arg0 + 0xD3) != 0) {
        return 0;
    }
    if (!(*(u16*)(arg0 + 0x80) & 0x80)) {
        return 0;
    }
    func_8003A874(arg0);
    return 1;
}
