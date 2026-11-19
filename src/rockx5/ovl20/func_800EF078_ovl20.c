#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800EF078_ovl20(u8* a0) {
    u8* p;
    u8* q;
    s32 i;

    a0[2]++;
    p = alloc_class6_slot();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xC;
        p[2] = 0;
        D_800D1C28[1] = 1;
    }
    p = alloc_class6_slot();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xC;
        p[2] = 0x10;
    }
    p = alloc_class6_slot();
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
    p = alloc_class6_slot();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xC;
        p[2] = 0x20;
    }
    p = alloc_class6_slot();
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
