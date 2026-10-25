/* Shared body (DK-5), from the banked draft of func_800F60D0_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s16 D_800FB628_ovl09;
extern s16 D_800FB62A_ovl09;

void DEDUP_NAME(u8* obj) {
    if (obj[0x15] == 0) {
        if (*(s16*)(obj + 0xA) > D_800FB628_ovl09) {
            goto done; // !FAKE: early exit to the shared tail; nested if/else does not match (C0074)
        }
    } else if (*(s16*)(obj + 0xA) < D_800FB62A_ovl09) {
        goto done; // !FAKE: early exit to the shared tail; nested if/else does not match (C0074)
    }
    *(s32*)(obj + 0x20) = 0;
    *(s16*)(obj + 0x7C) = 20;
    obj[6]++;
done:
    func_80017248(obj);
    func_8002DED4(obj);
}
