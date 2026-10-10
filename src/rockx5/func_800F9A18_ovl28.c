#include "types.h"

extern s16 D_8009A0AA;
extern void func_800171E8(Obj3DD4*, s32);
extern void func_8002D9EC(Obj3DD4*, s32, s32);
extern void func_80017248(Obj3DD4*);
extern void func_8002DED4(Obj3DD4*);

void func_800F9A18_ovl28(Obj3DD4* e) {
    func_800171E8(e, 5);
    if (D_8009A0AA > e->unkA) {
        e->unk15 = 0x40;
    } else {
        e->unk15 = 0;
    }
    e->unk20 = 0;
    e->unk7C = 0;
    e->unk6++;
    func_8002D9EC(e, 0x30, 0x30);
    func_80017248(e);
    func_8002DED4(e);
}
