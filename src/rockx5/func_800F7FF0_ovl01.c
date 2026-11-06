#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FD4EC_ovl01[][2];

void func_800F7FF0_ovl01(u8* arg0) {
    if (((s8*)arg0)[0x45] == 0x50) {
        func_800171E8(arg0, 2);
        *(s16*)(arg0 + 0x7C) = 50;
        arg0[6]++;
        return;
    }
    D_1F80004C.bytes[0x84] = -D_800FD4EC_ovl01[((s8*)arg0)[0x45]][0] - 8;
    D_1F80004C.bytes[0x86] = D_800FD4EC_ovl01[((s8*)arg0)[0x45]][0];
    D_1F80004C.bytes[0x85] = -D_800FD4EC_ovl01[((s8*)arg0)[0x45]][1];
    D_1F80004C.bytes[0x87] = D_800FD4EC_ovl01[((s8*)arg0)[0x45]][1] * 2;
}
