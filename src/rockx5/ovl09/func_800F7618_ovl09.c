#include "types.h"
#include "mmx5/globals.h"

extern void func_8002CF70(void);
extern s32 func_8003A190(u8*);

void func_800F7618_ovl09(u8* a0) {
    u8* p;

    if (a0[0x72] & 8) {
        p = g_Player;
        *(s16*)(p + 0xA) = *(s16*)(a0 + 0xA);
        *(s16*)(p + 0xE) = *(s16*)(a0 + 0xE) - (*(u8**)(a0 + 0x68))[3] -
                           (*(u8**)(p + 0x68))[3];
        func_8003D29C(0x14, p[0x15]);
        func_8002CF70();
        func_8003A190(p);
        a0[5] = 1;
    }
}
