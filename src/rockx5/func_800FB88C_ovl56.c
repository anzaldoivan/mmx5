#include "types.h"

extern void func_8002C1C8(void);
extern u8 D_800D1F3C;
extern signed char D_8009A424;
extern u8 D_8009A1F8[];

void func_800FB88C_ovl56(u8* a0) {
    if (D_800D1F3C == 0 && D_8009A424 == 0) {
        func_8002C1C8();
        D_8009A1F8[0x3] = 0;
        D_8009A1F8[0x57] = 0;
        D_8009A1F8[0xAB] = 1;
        *(s16*)(D_8009A1F8 + 0xB2) = 0;
        *(s16*)(D_8009A1F8 + 0xB6) = 0x500;
        D_8009A1F8[0xF4] = 1;
        a0[1]++;
    }
}
