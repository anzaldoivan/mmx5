#include "types.h"
#include "addr.h"

extern s32 func_8002DF78(void);
extern signed char D_800D1CA2;
extern u8 D_800FD518_ovl38[];
extern u8 D_800FD538_ovl38[];

void func_800FAC40_ovl38(u8* arg0) {
    arg0[6] = 0;
    *(s16*)(D_1F80004C.bytes + 0x84) = 0;
    if (D_1F80004C.bytes[0x90] == 0) {
        if (D_800D1CA2 / 2 >= *(s8*)(arg0 + 0x5C)) {
            D_1F80004C.bytes[0x8E] = func_8002DF78() & 7;
            D_1F80004C.bytes[0x8F] = 0;
            D_1F80004C.bytes[0x90] = 1;
            arg0[5] = D_800FD538_ovl38[D_1F80004C.bytes[0x8F] +
                                       D_1F80004C.bytes[0x8E] * 4];
            D_1F80004C.bytes[0x8F]++;
            return;
        }
    }
    switch (D_1F80004C.bytes[0x90]) {
    case 0: {
        u8* tbl = D_800FD518_ovl38;
        s32 row = D_1F80004C.bytes[0x8E] * 4;
        u8 v = tbl[D_1F80004C.bytes[0x8F] + row];
        if (v == 0xFF) {
            D_1F80004C.bytes[0x8E] = func_8002DF78() & 7;
            D_1F80004C.bytes[0x8F] = 0;
            row = D_1F80004C.bytes[0x8E] * 4;
            arg0[5] = tbl[D_1F80004C.bytes[0x8F] + row];
        } else {
            arg0[5] = v;
        }
        break;
    }
    case 1: {
        u8* tbl = D_800FD538_ovl38;
        s32 row = D_1F80004C.bytes[0x8E] * 4;
        u8 v = tbl[D_1F80004C.bytes[0x8F] + row];
        if (v == 0xFF) {
            D_1F80004C.bytes[0x8E] = func_8002DF78() & 7;
            D_1F80004C.bytes[0x8F] = 0;
            row = D_1F80004C.bytes[0x8E] * 4;
            arg0[5] = tbl[D_1F80004C.bytes[0x8F] + row];
        } else {
            arg0[5] = v;
        }
        break;
    }
    default:
        return;
    }
    D_1F80004C.bytes[0x8F]++;
}
