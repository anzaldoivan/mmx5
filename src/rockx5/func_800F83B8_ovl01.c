#include "types.h"

extern ObjFAF38* func_8002D1A4();

void func_800F83B8_ovl01(ObjFAF38* arg0) {
    ObjFAF38* obj = func_8002D1A4(arg0);

    if (obj != 0) {
        obj->unk0 = 0x41;
        obj->unk1 = 0x2C;
        obj->unk7C = arg0;
        obj->unk2 = 0;
        obj->unkA = arg0->unkA;
        obj->unk8 = 0;
        obj->unkE = arg0->unkE;
        obj->unkC = 0;
        obj->unk42 = arg0->unk42 & 0x7FFF;
        obj->unk30 = arg0->unk30;
        obj->unk3C = arg0->unk3C;
        obj->unk40 = arg0->unk40;
        obj->unk14 = arg0->unk14;
    }
}
