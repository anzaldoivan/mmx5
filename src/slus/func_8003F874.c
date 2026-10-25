#include "types.h"

extern void* func_8003D4C0(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern s32 func_8002DF78(void);
extern void func_8003CF74(u8*, s32);

void func_8003F874(u8* arg0) {
    s8 t;

    func_8003D4C0(0x21, 2, *(s8*)(arg0 + 0x96), 0);
    t = *(s8*)(arg0 + 0x96);
    if (t == 0x12 || t == 0x14 || t == 0x2E || t == 0x13) {
        if (func_8002DF78() & 1) {
            func_8003CF74(arg0, 6);
        }
    }
}
