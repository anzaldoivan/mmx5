#include "types.h"

extern void func_80016490(s32, s32, void*);
extern u8* func_8002D0E4(void);
extern s32 func_8002DF78(void);
extern s32 func_8002DFB0(void);
extern s32 D_8009A420;
extern s32 D_800FC00C_ovl01[];
extern s32 D_800FC01C_ovl01[];

void func_800EFC40_ovl01(void) {
    u8* obj;
    s32 t;
    s32 i;
    s32 r;

    obj = func_8002D0E4();
    if (obj != 0) {
        obj[0] = 0x21;
        obj[1] = 4;
        obj[2] = 1;
        obj[4] = 0;
        obj[5] = 0;
        obj[6] = 0;
        obj[0x5C] = 0xFF;
        i = func_8002DF78();
        t = D_800FC01C_ovl01[i & 3];
        *(s32*)(obj + 8) = 0;
        *(s32*)(obj + 0x20) = t;
        r = func_8002DFB0();
        obj[0x15] = 0;
        *(s8*)(obj + 0x14) = -1;
        obj[0x16] = 1;
        *(s16*)(obj + 0xE) = r % 240;
    }
    if (!(D_8009A420 & 3)) {
        func_80016490(0, D_800FC00C_ovl01[func_8002DF78() & 3], 0);
    }
}
