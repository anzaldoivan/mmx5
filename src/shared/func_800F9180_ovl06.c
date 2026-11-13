/* Shared body (DK-5), from the banked draft of func_800F9180_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s32 DEDUP_CALLEE(void);
extern u8 D_800FF194_ovl06[][0x12];
extern u8 D_800FF17C_ovl06[];
extern u8 D_800FF188_ovl06[];
extern u8 D_800FF170_ovl06[];

void DEDUP_NAME(u8* o) {
    u8* g;

    if (D_1F80004C.bytes[0x87] == 0) {
        if (((s8*)o)[0x5C] < (D_1F80004C.bytes[0x86] * 2) / 3) {
            D_1F80004C.bytes[0x87] = 1;
            D_1F80004C.bytes[0x88] = D_800FF194_ovl06[1][DEDUP_CALLEE() & 0xF];
            D_1F80004C.bytes[0x89] = 0;
            o[5] = D_800FF17C_ovl06[D_1F80004C.bytes[0x89] +
                                    D_1F80004C.bytes[0x88] * 5];
            o[6] = 0;
            return;
        }
    } else if (D_1F80004C.bytes[0x87] == 1) {
        if (((s8*)o)[0x5C] < (u8)(D_1F80004C.bytes[0x86] / 3U)) {
            D_1F80004C.bytes[0x87] = 2;
            D_1F80004C.bytes[0x88] = D_800FF194_ovl06[2][DEDUP_CALLEE() & 0xF];
            D_1F80004C.bytes[0x89] = 0;
            o[5] = D_800FF188_ovl06[D_1F80004C.bytes[0x89] +
                                    D_1F80004C.bytes[0x88] * 6];
            o[6] = 0;
            return;
        }
    }

    g = D_1F80004C.bytes;
    switch (g[0x87]) {
    case 0: {
        u8 v0;
        g[0x89]++;
        v0 = D_800FF170_ovl06[D_1F80004C.bytes[0x89] +
                              D_1F80004C.bytes[0x88] * 5];
        if (v0 == 0xFF) {
            D_1F80004C.bytes[0x88] = D_800FF194_ovl06[0][DEDUP_CALLEE() & 0xF];
            D_1F80004C.bytes[0x89] = 0;
            o[5] = D_800FF170_ovl06[D_1F80004C.bytes[0x89] +
                                    D_1F80004C.bytes[0x88] * 5];
        } else {
            o[5] = v0;
        }
        break;
    }
    case 1: {
        u8 v1;
        g[0x89]++;
        v1 = D_800FF17C_ovl06[D_1F80004C.bytes[0x89] +
                              D_1F80004C.bytes[0x88] * 5];
        if (v1 == 0xFF) {
            D_1F80004C.bytes[0x88] = D_800FF194_ovl06[1][DEDUP_CALLEE() & 0xF];
            D_1F80004C.bytes[0x89] = 0;
            o[5] = D_800FF17C_ovl06[D_1F80004C.bytes[0x89] +
                                    D_1F80004C.bytes[0x88] * 5];
        } else {
            o[5] = v1;
        }
        break;
    }
    case 2: {
        u8 v2;
        g[0x89]++;
        v2 = D_800FF188_ovl06[D_1F80004C.bytes[0x89] +
                              D_1F80004C.bytes[0x88] * 6];
        if (v2 == 0xFF) {
            D_1F80004C.bytes[0x88] = D_800FF194_ovl06[2][DEDUP_CALLEE() & 0xF];
            D_1F80004C.bytes[0x89] = 0;
            o[5] = D_800FF188_ovl06[D_1F80004C.bytes[0x89] +
                                    D_1F80004C.bytes[0x88] * 6];
        } else {
            o[5] = v2;
        }
        break;
    }
    }
    o[6] = 0;
}
