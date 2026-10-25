/* Shared body (DK-5), from the banked draft of func_800FE04C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(Ent800FE04C*);
extern void func_8002DF54(Ent800FE04C*);
extern s32 func_800FD530_ovl07(Ent800FE04C*, s32);
extern void func_800171E8(Ent800FE04C*, s32);
extern s32 func_8002FB58(Ent800FE04C*);

void DEDUP_NAME(Ent800FE04C* o) {
    func_80017248(o);
    func_8002DF54(o);
    if (func_800FD530_ovl07(o, 0) != 0) {
        o->unk3 = 0;
        o->unkE = o->unk94;
        if (o->unk8D == 0) {
            func_800171E8(o, 0xE);
        } else {
            func_800171E8(o, 0x18);
        }
        o->unk8E = 1;
        o->unk6 = 3;
        return;
    }
    func_8002FB58(o);
    if (!(o->unk70 & 4)) {
        return;
    }
    if (o->unk8D == 0) {
        func_800171E8(o, 0xD);
    } else {
        func_800171E8(o, 0x18);
    }
    o->unk67 = 0;
    o->unk20 = 0;
    o->unk24 = 0;
    o->unk6++;
}
