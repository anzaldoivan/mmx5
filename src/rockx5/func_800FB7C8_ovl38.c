#include "types.h"
#include "addr.h"

extern s32 func_800317B8(u8* a0);
extern void (*D_800FD978_ovl38[])(u8*);

void func_800FB7C8_ovl38(u8* a0) {
    if (((s8*)*(u8**)(D_1F80004C.bytes + 0x80))[4] == 2) {
        a0[3] = 0;
        a0[4]++;
    } else {
        D_800FD978_ovl38[(s8)a0[5]](a0);
        if ((s8)a0[2] == 4 && ((s8*)a0)[3] != 0) {
            func_800317B8(a0);
        }
    }
}
