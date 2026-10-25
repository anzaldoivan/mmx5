/* Shared body (DK-5), from the banked draft of func_800F6A34_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void DEDUP_NAME(u8* obj) {
    u8* plr;
    s32 target;

    func_80017248(obj);
    plr = D_8009A0A0;
    if (*(s16*)(plr + 0xA) < *(s16*)(obj + 0xA)) {
        target = *(s16*)(plr + 0xE) - 8;
        if (*(s16*)(obj + 0xE) < target) {
            *(s16*)(obj + 0xE) += 1;
        } else if (target < *(s16*)(obj + 0xE)) {
            *(s16*)(obj + 0xE) -= 1;
        }
    }
    func_8002DF54(obj);
}
