#include "types.h"
#include "mmx5/ovl03.h"
#include "mmx5/globals.h"

extern void (*D_800F9DDC_ovl03[])(u8*);

void func_800F2BD4_ovl03(u8* obj) {
    u8* p;

    D_800F9DDC_ovl03[(s8)obj[5]](obj);
    if (D_800FA238_ovl03.s != 0) {
        if (obj[0x47] == 14) {
            animate_object(obj);
        }
    } else {
        animate_object(obj);
    }
    ((s32(*)())func_8002D89C)(obj);
    if (((s8*)obj)[2] != 0) {
        return;
    }
    if (D_8009A0AA < 0x1081) {
        return;
    }
    p = D_8009A1F8.u;
    if ((s8)p[0xAC] != 2) {
        p[0xAC] = 2;
        p[0xF4] = 1;
        p[0x57] = 0;
    }
}

#define D_800EEBA0_ovl00 func_800F2CA4_ovl03
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEBA0_ovl00 func_800F2CC4_ovl03
#define func_8002D720 func_8002D89C
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F2CE4_ovl03
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
