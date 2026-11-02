#include "types.h"

extern void func_80016490(s32, s32, void*);
extern u8* func_8002D1A4();
extern void func_800171E8(u8* obj, s32 state);
extern s16 D_8009A0AA;

void func_800F9794_ovl28(u8* arg0) {
    u8* p;

    if (*(s8*)(arg0 + 0x45) == 1) {
        func_80016490(2, 0x91, arg0);
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 3;
            *(u8**)(p + 0x7C) = arg0;
        }
    }
    if (*(s8*)(arg0 + 0x46) == 0) {
        func_800171E8(arg0, 2);
    }
    if (*(s8*)(arg0 + 7) == 1) {
        func_800171E8(arg0, 3);
        if (D_8009A0AA > *(s16*)(arg0 + 0xA)) {
            arg0[0x15] = 0x40;
        } else {
            arg0[0x15] = 0;
        }
        arg0[6]++;
    }
}
