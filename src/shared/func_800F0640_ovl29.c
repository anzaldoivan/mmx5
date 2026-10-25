/* Shared body (DK-5), from the banked draft of func_800F0640_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(Ent0640*);
extern void func_8002DED4(Ent0640*);

void DEDUP_NAME(Ent0640* obj) {
    u8 mode;

    func_80017248(obj);
    if (obj->unk45 == 2) {
        obj->unk80 = 1;
        obj->unk24 = 0x60000;
        mode = obj->unk8C;
        obj->unk2C = 0x4000;
        if (mode == 0) {
            if (obj->unk15 == 0) {
                obj->unk20 = -0x1CCCC;
            } else {
                obj->unk20 = 0x1CCCC;
            }
        } else if (mode == 1) {
            obj->unk20 = 0;
        } else if (mode == 2) {
            if (obj->unk15 == 0) {
                obj->unk20 = 0x1CCCC;
            } else {
                obj->unk20 = -0x1CCCC;
            }
        }
        func_8002DED4(obj);
        obj->unk06 = 1;
    }
}
