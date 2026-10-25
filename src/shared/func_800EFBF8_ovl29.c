/* Shared body (DK-5), from the banked draft of func_800EFBF8_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(EntFBF8*);
extern void func_8002DF54(EntFBF8*);

void DEDUP_NAME(EntFBF8* obj) {
    s32 v;

    func_80017248(obj);
    func_8002DF54(obj);
    if (--obj->unk7C == 0) {
        v = -0x20000;
        if (obj->unk15 & 0x40) {
            v = 0x20000;
        }
        obj->unk20 = v;
        obj->unk5 = 5;
        obj->unk6 = 0;
    }
}
