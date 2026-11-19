#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80093E10[];

void func_80022F90(void) {
    u8* src = g_Player;
    u8* dst = D_80093E10;

    if (*(s8*)dst != 0) {
        *(s32*)(dst + 8) = *(s32*)(src + 8);
        *(s32*)(dst + 0xC) = *(s32*)(src + 0xC);
        if (*(s8*)(src + 0x14B) != 0) {
            dst[3] = 1;
        } else {
            dst[3] = 0;
        }
        animate_object(dst);
    }
}
