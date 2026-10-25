#include "types.h"

extern u8* func_8002D27C(void);
extern u8 D_80070F28[];

void func_8001F1B0(u8* a0) {
    u8* obj;
    u32 i;

    for (i = 0; i < 1; i++) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x13;
            obj[2] = D_80070F28[i];
        }
    }
    *(u16*)(a0 + 4) = 0x258;
    a0[0xD] = 0;
    a0[1]++;
}
