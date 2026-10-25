#include "types.h"

extern ObjFAF38* func_8002D1A4();

void func_800FB104_ovl27(ObjFAF38* arg0, s16 arg1, s16 arg2) {
    ObjFAF38* obj = func_8002D1A4();

    if (obj != 0) {
        obj->unk0 = 0x41;
        obj->unk1 = 0x21;
        obj->unk7C = arg0->unk7C;
        obj->unk2 = 4;
        obj->unk42 = arg0->unk42 & 0x7FFF;
        obj->unk30 = arg0->unk30;
        obj->unk3C = arg0->unk3C;
        obj->unk40 = arg0->unk40;
        obj->unk14 = arg0->unk14;
        obj->unk8 = 0;
        obj->unkC = 0;
        obj->unkA = arg1;
        obj->unkE = arg2;
    }
}
