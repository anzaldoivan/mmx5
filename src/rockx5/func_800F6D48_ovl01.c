#include "types.h"
#include "addr.h"

extern ObjFAF38* func_8002D1A4();
extern u8 D_800FCEF0_ovl01[];

void func_800F6D48_ovl01(ObjFAF38* arg0) {
    ObjFAF38* obj = func_8002D1A4(arg0);

    if (obj != 0) {
        obj->unk0 = 0x41;
        obj->unk1 = 4;
        obj->unk2 = 2;
        obj->unk7C = D_1F80004C.scr780->unk80;
        obj->unkA = arg0->unkA;
        obj->unkE = arg0->unkE;
        obj->unk42 = arg0->unk42 & 0x7FFF;
        obj->unk30 = (s32)D_800FCEF0_ovl01;
        obj->unk3C = arg0->unk3C;
        obj->unk40 = arg0->unk40;
        ((u8*)obj)[0x15] = 0;
        obj->unk14 = arg0->unk14;
    }
}
