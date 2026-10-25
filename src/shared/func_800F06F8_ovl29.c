/* Shared body (DK-5), from the banked draft of func_800F06F8_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DED4(Ent06F8*);
extern void func_80017248(Ent06F8*);
extern void func_800171E8(Ent06F8*, s32);

void DEDUP_NAME(Ent06F8* obj) {
    func_8002DED4(obj);
    func_80017248(obj);
    if (obj->unk24 == 0 && obj->unk8C != 0) {
        obj->unk2C = 0;
        obj->state = 2;
        obj->substate = 0;
    }
    if (obj->flags70 & 8) {
        obj->unk24 = 0;
        obj->unk2C = 0;
        func_800171E8(obj, 0x11);
        obj->substate = 2;
    }
}
