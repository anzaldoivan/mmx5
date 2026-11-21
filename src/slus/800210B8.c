#include "types.h"
#include "mmx5/globals.h"

extern void func_800F2E80_ovl24();
#define D_800EEBA0_ovl00 func_800210B8
#define func_8002D720 func_800F2E80_ovl24
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern s32 func_80013674(void);
extern u8 D_8009A428;

void func_800210D8(u8* arg0) {
    D_8009A428 = 0;
    arg0[0] = 0x14;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[0x1F] = 0;
    arg0[0x24] = 0;
    arg0[0xC] = 0xB;
    arg0[0xD] = 0;
    func_80013674();
}
