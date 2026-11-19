#include "types.h"
#include "mmx5/globals.h"

extern s32 func_8002DC14(void);
extern void func_8002DC44(void);
extern s8 D_8007D784[];
extern u8 D_800D1C00[];

void func_80056D94(u8* arg0) {
    if ((s8)g_Player[5] == 0x14) {
        D_800D1C00[0x1C] = 1;
        func_8002DC44();
        arg0[0] |= 8;
        D_800D1C00[0x16] = 1;
        D_800D1C00[0x12] = 1;
        D_800D1C00[0x13] = 1;
        D_800D1C00[0x19] = 1;
        D_800D1C00[0x18] = 1;
        D_800D1C00[0x17] = 1;
        D_800D1C00[0x14] = 1;
        D_800D1C00[0x15] = 1;
        ((s32(*)())func_8002385C)(
            D_8007D784[((s8*)arg0)[2] + func_8002DC14() * 0x35] - 1, 0xFF, 0);
        arg0[5]++;
        g_Player[0x71] |= 8;
    }
}
