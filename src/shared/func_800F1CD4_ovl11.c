/* Shared body (DK-5), from the banked draft of func_800F1CD4_ovl11 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004AD78.c via src/slus/func_80050C60.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern int func_8002D6FC();
extern void func_8002D89C(u8*);
extern s32 D_8009A420;

void DEDUP_NAME(u8* arg0) {
    u8 temp_v1;

    func_8002DF54(arg0);
    func_80017248(arg0);
    if (*(s8*)(arg0 + 0x46) == 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        arg0[0x54] = 0;
        func_8002D6FC(arg0);
        return;
    }
    temp_v1 = arg0[0x54];
    arg0[3] = 0;
    if (!(temp_v1 & 3) || (temp_v1 & 1)) {
        if ((D_8009A420 & 1) == *(s8*)(arg0 + 7)) {
            func_8002D89C(arg0);
        }
    } else {
        func_8002D89C(arg0);
    }
}
