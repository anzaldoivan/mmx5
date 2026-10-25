/* Shared body (DK-5), from the banked draft of func_800EF920_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DED4(EntF920*);
extern void func_80017248(EntF920*);

void DEDUP_NAME(EntF920* obj) {
    s32 v = obj->velX;
    if ((v >= 0 ? v : -v) <= 0xFFFF || ((obj->flags & 2) && obj->unk15 == 0) ||
        ((obj->flags & 1) && obj->unk15 != 0)) {
        obj->unk60 = 3;
        obj->velX = 0;
        obj->unk28 = 0;
        obj->state = 7;
        obj->substate = 0;
    }
    func_8002DED4(obj);
    func_80017248(obj);
}
