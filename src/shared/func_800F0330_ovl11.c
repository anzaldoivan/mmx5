/* Shared body (DK-5), from the banked draft of func_800F0330_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];
extern u8 D_800F9730_ovl11[];
extern s32 func_8002E804(u8*, u8*);
extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern void func_800EFFA0_ovl11(u8*, s32, s32);

void DEDUP_NAME(u8* arg0) {
    u8* p;
    s32 r;

    if ((D_8009A0A0[0x5C] & 0x7F) && func_8002E804(arg0, D_8009A0A0)) {
        arg0[5] = 0;
        p = D_800D1C00;
        if ((signed char)++p[0x45] >= 10) {
            p[0x45] = 9;
        } else {
            func_80016490(0, 0x15, 0);
        }
        r = func_8002DF78() & 3;
        func_800EFFA0_ovl11(arg0, D_800F9730_ovl11[r], r);
    }
}
