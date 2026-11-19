#include "types.h"

void func_8003AD78(u8* arg0);

s32 try_wall_jump(u8* arg0) {
    if (*(signed char*)(arg0 + 0xD3) != 0) {
        return 0;
    }
    if (!(*(u16*)(arg0 + 0x80) & 0x80)) {
        return 0;
    }
    if (*(signed char*)(arg0 + 0x4A) <= 0) {
        return 0;
    }
    func_8003AD78(arg0);
    return 1;
}
