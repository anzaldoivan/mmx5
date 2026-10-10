/* Shared body (DK-5), from the banked draft of func_800F2178_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016D54(s32, s32);
extern void func_8002D720(Obj800F2688*);

void DEDUP_NAME(Obj800F2688* arg0) {
    if (--arg0->unk7C != -1) {
        if (((Ent2*)arg0)->unk2 == 1) {
            func_80016D54(2, 0xF);
        }
        func_8002D720(arg0);
    }
}
