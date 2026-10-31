/* Shared body (DK-5), from the banked draft of func_800FB5A4_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s32 D_80093DD0[];
extern u8 D_800C9310;
extern s8 D_800D1C00[];
extern u8 D_80101C10_ovl07[][2];

void DEDUP_NAME(void) {
    s32 i;

    if (D_1F80004C.s8s[0x96] != 0) {
        if (--D_1F80004C.s8s[0x95] == 0) {
            if (!(D_1F80004C.bytes[0x96] & 1)) {
                for (i = 0; i < 16; i++) {
                    D_80093DD0[i] = 0;
                }
                D_800C9310 |= 1;
            } else {
                for (i = 2; i < 16; i++) {
                    D_80093DD0[i] = 0;
                }
                if (D_800D1C00[0xC] == 0xC) {
                    D_80093DD0[2] = 0x9000C000;
                } else {
                    D_80093DD0[0] = 0xF0;
                    D_80093DD0[2] = 0x40FF;
                    D_80093DD0[1] = 0;
                    D_80093DD0[3] = 0xA0004000;
                    D_80093DD0[4] = 0x40000000;
                }
                D_800C9310 |= 1;
            }
            D_1F80004C.bytes[0x95] = D_80101C10_ovl07[D_1F80004C.s8s[0x97]][1];
            D_1F80004C.bytes[0x96]--;
        }
    }
}
