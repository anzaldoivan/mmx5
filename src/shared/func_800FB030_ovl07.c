/* Shared body (DK-5), from the banked draft of func_800FB030_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s32 DEDUP_CALLEE(void);
extern u8 D_8010178C_ovl07[][0x12];
extern u8 D_801017B0_ovl07[];
extern u8 D_801017C4_ovl07[];
extern u8 D_801017E4_ovl07[];

void DEDUP_NAME(u8* obj) {
    u8* t;
    u8 v;
    u8 w;

    if (D_1F80004C.bytes[0x8B] == 0) {
        if (((s8*)obj)[0x5C] < (D_1F80004C.bytes[0x8A] * 2) / 3) {
            D_1F80004C.bytes[0x8C] = D_8010178C_ovl07[0][DEDUP_CALLEE() & 0xF];
            D_1F80004C.bytes[0x8D] = 0;
            D_1F80004C.bytes[0x8B] = 1;
            obj[5] = D_801017C4_ovl07[D_1F80004C.bytes[0x8D] +
                                      D_1F80004C.bytes[0x8C] * 10];
            obj[6] = 0;
            return;
        }
    } else if (D_1F80004C.bytes[0x8B] == 1) {
        if (((s8*)obj)[0x5C] < (u8)(D_1F80004C.bytes[0x8A] / 3)) {
            D_1F80004C.bytes[0x8C] = D_8010178C_ovl07[1][DEDUP_CALLEE() & 0xF];
            D_1F80004C.bytes[0x8D] = 0;
            D_1F80004C.bytes[0x8B] = 2;
            obj[5] = D_801017E4_ovl07[D_1F80004C.bytes[0x8D] +
                                      D_1F80004C.bytes[0x8C] * 10];
            obj[6] = 0;
            return;
        }
    }

    switch (D_1F80004C.bytes[0x8B]) {
    case 0:
        D_1F80004C.bytes[0x8C]++;
        v = D_801017B0_ovl07[D_1F80004C.bytes[0x8C]];
        if (v == 0xFF) {
            D_1F80004C.bytes[0x8C] = 0;
            obj[5] = D_801017B0_ovl07[D_1F80004C.bytes[0x8C]];
        } else {
            obj[5] = v;
        }
        break;
    case 1:
        D_1F80004C.bytes[0x8D]++;
        t = D_1F80004C.bytes;
        w = D_801017C4_ovl07[t[0x8D] + t[0x8C] * 10];
        if (w == 0xFF) {
            D_1F80004C.bytes[0x8C] = D_8010178C_ovl07[0][DEDUP_CALLEE() & 0xF];
            D_1F80004C.bytes[0x8D] = 0;
            t = D_1F80004C.bytes;
            obj[5] = D_801017C4_ovl07[t[0x8D] + t[0x8C] * 10];
        } else {
            obj[5] = w;
        }
        break;
    case 2:
        D_1F80004C.bytes[0x8D]++;
        t = D_1F80004C.bytes;
        w = D_801017E4_ovl07[t[0x8D] + t[0x8C] * 10];
        if (w == 0xFF) {
            D_1F80004C.bytes[0x8C] = D_8010178C_ovl07[1][DEDUP_CALLEE() & 0xF];
            D_1F80004C.bytes[0x8D] = 0;
            t = D_1F80004C.bytes;
            obj[5] = D_801017E4_ovl07[t[0x8D] + t[0x8C] * 10];
        } else {
            obj[5] = w;
        }
        break;
    }
    obj[6] = 0;
}
