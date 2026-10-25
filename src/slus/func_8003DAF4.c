#include "types.h"

extern u8* func_8002D27C(void);
extern s8 D_800748B0[];

void func_8003DAF4(s8 arg0) {
    s8* p;
    s8 val;
    u8* obj;
    u32 i;
    s32 kind;
    s32 sub;
    s32 idx;
    s8* base;

    i = 0;
    kind = 0x21;
    idx = arg0;
    base = D_800748B0;
    p = base + idx * 8;
    sub = 0x11;
    for (; i < 8; i++, p++) {
        val = *p;
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = kind;
            obj[1] = sub;
            obj[2] = val;
            obj[4] = 0;
            obj[5] = 0;
            obj[6] = 0;
        }
    }
}
