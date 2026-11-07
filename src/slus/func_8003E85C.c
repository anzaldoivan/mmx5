#include "types.h"

extern void func_8003C5D8(u8* obj);
extern void func_8003CEDC(u8* arg0, s32 arg1);
extern s32 func_8003E96C(u8* p);
extern void func_8003EA98(u8* p);
extern void func_8003F250(u8* p);
extern s32 func_8003FCC0(u8* p, s32 i);
extern void func_8003FD24(u8* p);

void func_8003E85C(u8* p) {
    s8 st;

    if (((s8*)p)[2] != 0) {
        return;
    }
    if (((s8*)p)[0xF0] != 0) {
        return;
    }
    if (((s8*)p)[0xF3] != 0) {
        return;
    }
    st = ((s8*)p)[5];
    if (st == 0) {
        return;
    }
    if (st == 1) {
        return;
    }
    if (st == 0x19) {
        return;
    }
    if (st == 0x18) {
        return;
    }
    if (((s8*)p)[0xD5] != 0) {
        return;
    }
    if (func_8003E96C(p) != 0) {
        func_8003F250(p);
        if (((s8*)p)[0xA2] != 0) {
            func_8003CEDC(p, 0x32);
        } else {
            func_8003C5D8(p);
        }
        return;
    }
    if (!(*(s32*)(p + 0xFC) & 0x1000)) {
        func_8003EA98(p);
        func_8003FD24(p);
        if (func_8003FCC0(p, 0) == 0) {
            func_8003FCC0(p, 1);
        }
    }
}
