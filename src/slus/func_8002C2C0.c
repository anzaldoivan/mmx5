#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800C9310;
extern void func_8002C088(s32, s32);

void func_8002C2C0(void) {
    u8* p = g_Player;
    u8 s = p[0xF7];

    if (s != 0) {
        if (s == 1) {
            func_8002C088(0, 0x200);
            p[0xF7] = 2;
        } else if (D_800C9310 != 0) {
            func_8002C088(0, 2);
            func_8002C088(0x13, 0x15);
        }
    }
}
