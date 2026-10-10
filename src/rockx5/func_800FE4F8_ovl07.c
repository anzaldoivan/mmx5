#include "types.h"

extern void func_80017248(EntFE4F8*);
extern void func_8002DF54(EntFE4F8*);
extern s32 func_800FD530_ovl07(EntFE4F8*, s32);
extern void func_800171E8(EntFE4F8*, s32);
extern s32 func_8002FB58(EntFE4F8*);

void func_800FE4F8_ovl07(EntFE4F8* o) {
    func_80017248(o);
    func_8002DF54(o);
    if (func_800FD530_ovl07(o, 1) != 0) {
        o->unk3 = 0;
        o->unkA = o->unk92;
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
    if (!(o->unk70 & 2)) {
        return;
    }
    if (o->unk8D == 0) {
        func_800171E8(o, 9);
    } else {
        func_800171E8(o, 0x18);
    }
    o->unk67 = 0;
    o->unk20 = 0;
    o->unk24 = 0;
    o->unk6++;
}
