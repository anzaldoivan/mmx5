/* Shared body (DK-5), from the banked draft of func_800F6010_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016D54(s32, s32);
extern ObjFAF38* func_8002D1A4();
extern s32 func_80016490(s32, s32, void*);
extern void func_80017248(Obj3DD4*);
extern void func_8002DED4(Obj3DD4*);

void DEDUP_NAME(Obj3DD4* o) {
    ObjFAF38* c;

    if (--o->unk7C == 0) {
        func_80016D54(2, 0x26);
        c = func_8002D1A4();
        if (c != 0) {
            func_80016490(2, 0x25, o);
            c->unk0 = 0x41;
            c->unk1 = 0x10;
            c->unk2 = 3;
            c->unk7C = o;
        }
        if (o->unk15 != 0) {
            o->unk20 = 0x20000;
        } else {
            o->unk20 = -0x20000;
        }
        o->unk6++;
    }
    func_80017248(o);
    func_8002DED4(o);
}
