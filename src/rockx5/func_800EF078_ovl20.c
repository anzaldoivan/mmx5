#include "types.h"

extern u8* func_8002D53C(void);
extern u8* func_8002D27C(void);
extern s8 D_800D1C28[];

void func_800EF078_ovl20(u8* a0) {
    u8* p;
    u8* q;
    s32 i;

    a0[2]++;
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xC;
        p[2] = 0;
        D_800D1C28[1] = 1;
    }
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xC;
        p[2] = 0x10;
    }
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xC;
        p[2] = 0x30;
    }
    for (i = 0; i < 14; i++) {
        q = func_8002D27C();
        if (q != 0) {
            q[0] = 0x41;
            q[1] = 0xF;
            q[2] = i;
        }
    }
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xC;
        p[2] = 0x20;
    }
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xC;
        p[2] = 0x40;
    }
    for (i = 0; i < 4; i++) {
        if (i == 1 && (a0[0x10F] == 2 || a0[0x10F] == 4)) {
            continue;
        }
        q = func_8002D27C();
        if (q != 0) {
            q[0] = 0x41;
            q[1] = 0x2C;
            q[2] = i;
        }
    }
    for (i = 0; i < 4; i++) {
        if (i == 1 && (a0[0x10F] == 2 || a0[0x10F] == 4)) {
            continue;
        }
        q = func_8002D27C();
        if (q != 0) {
            q[0] = 0x41;
            q[1] = 0x2C;
            q[2] = i + 7;
        }
    }
}
