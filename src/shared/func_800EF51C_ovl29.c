/* Shared body (DK-5), from the banked draft of func_800EF51C_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Obj800EF51C*, s32);
extern void func_80017248(Obj800EF51C*);
extern void func_8002DF54(Obj800EF51C*);

void DEDUP_NAME(Obj800EF51C* obj) {
    if (obj->unk88 == 0) {
        if (--obj->unk8C == 0) {
            func_800171E8(obj, 2);
            obj->unk5 = 3;
            obj->unk6 = 0;
            obj->unk8C = 0x78;
        }
    }
    func_8002DF54(obj);
    func_80017248(obj);
}
