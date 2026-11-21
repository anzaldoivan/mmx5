#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern int func_8002D7A0();

void func_800F26EC_ovl11(u8* arg0) {
    if (D_1F80004C.bytes[0x86] == 0) {
        if (((s8*)arg0)[4] == 4) {
            func_8002D7A0(arg0);
        } else {
            func_8002D760(arg0);
        }
    } else if (((s8*)arg0)[2] == 9) {
        if (((s8*)arg0)[4] == 4) {
            func_8002D7A0(arg0);
        } else {
            func_8002D760(arg0);
        }
    } else {
        func_8002D720(arg0);
    }
}

extern s32 D_8009A0A8;
extern s16 D_800F9974_ovl11[];

void func_800F2780_ovl11(u8* arg0) {
    s16* tbl;
    s32 d;
    s32 idx;
    u8* scr;
    u8 n;

    if (((s8*)arg0)[6] == 0) {
        d = D_8009A0AA;
        tbl = D_800F9974_ovl11;
        idx = ((s8*)arg0)[2] - 6;
        if (d - *(s16*)(arg0 + 0xA) >= tbl[idx]) {
            D_1F80004C.bytes[0x81] = idx * 0x10;
            arg0[6]++;
        }
    } else {
        scr = D_1F80004C.bytes;
        n = scr[0x81];
        if (n == 0) {
            arg0[4] = 1;
            arg0[5] = 2;
            arg0[6] = 0;
            arg0[0x7A] = 0;
            if (D_8009A0A8 < *(s32*)(arg0 + 8)) {
                arg0[0x15] = 0;
                return;
            }
            arg0[0x15] = 0x40;
            return;
        }
        scr[0x81] = n - 1;
    }
}
