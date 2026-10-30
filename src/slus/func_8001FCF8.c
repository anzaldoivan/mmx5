#include "types.h"

extern void func_8002C50C(void);
extern u8* func_8002D27C(void);
extern u8 D_80070C54;
extern u8 D_8009A427;
extern u8 D_80070FB8;
extern u8 D_80070FD0;

static inline u8* func_8001FCF8_spawn(u8* p) {
    u8* obj;
    u8 i;
    s32 one;

    i = 0;
    one = 1;
    if (*p != 0) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = one;
            obj[1] = 0x20;
            *(u8**)(obj + 0x50) = p;
            *(u16*)(obj + 0xA) = *p++;
            obj[0x55] = one;
        }
    } else {
        p++;
    }
    while (*p != 0xFF) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x1F;
            obj[2] = *p++;
            obj[7] = i++;
            *(u16*)(obj + 0xE) = *p++;
            *(u16*)(obj + 0xA) = *p++;
            obj[0x55] = one;
        }
    }
    return p;
}

void func_8001FCF8(u8* arg0) {
    u8* p;

    func_8002C50C();
    D_8009A427 = 0;
    if (D_80070C54 != 0xFF) {
        p = func_8001FCF8_spawn(&D_80070FB8);
        *(u16*)(arg0 + 8) = p[1];
        arg0[1] = 1;
    } else {
        p = func_8001FCF8_spawn(&D_80070FD0);
        *(u16*)(arg0 + 8) = p[1];
        arg0[1] = 3;
    }
}
