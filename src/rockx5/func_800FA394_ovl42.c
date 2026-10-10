#include "types.h"

extern u8 D_800D1F3C;
extern signed char D_8009A424;
extern u8 D_8009A1F8[];
extern void func_8001E668(void);
extern void func_8002C50C(void);

void func_800FA394_ovl42(u8* arg0) {
    s32 i;
    u8* p;

    if (D_800D1F3C == 0 && D_8009A424 == 0) {
        func_8001E668();
        D_8009A1F8[0x3] = 0;
        D_8009A1F8[0x57] = 0;
        D_8009A1F8[0xAB] = 0;
        func_8002C50C();
        i = 15;
        p = arg0 + 0x35;
        for (; i >= 0; i--) {
            *p-- = 0;
        }
        arg0[0x10F] = 1;
        arg0[0] = 0x15;
    }
}
