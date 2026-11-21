#include "types.h"
#include "mmx5/globals.h"

extern void func_800392E4();
#define D_800EEBA0_ovl00 func_800446A0
#define func_8002D720 func_800392E4
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern void func_8003A9AC(void);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);

void func_800446C0(u8* obj) {
    if (obj[0x89] & 8) {
        obj[0x8E] = 0;
        func_8003A9AC();
    } else if (*(signed char*)(obj + 0x46) == 0) {
        func_8003B4CC(obj, 0xB, 4);
        obj[0x8E] = 0;
        obj[5] = 7;
        obj[6] = 0;
    }
}
