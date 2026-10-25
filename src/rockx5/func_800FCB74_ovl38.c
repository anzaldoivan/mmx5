#include "types.h"

extern ObjFAF38* func_8002D1A4();

void func_800FCB74_ovl38(ObjFAF38* arg0, u8 arg1) {
    ObjFAF38* obj = func_8002D1A4(arg0);

    if (obj != 0) {
        obj->unk0 = 0x61;
        obj->unk1 = 0x25;
        obj->pad15[0] = arg0->pad15[0];
        obj->unk7C = arg0;
        obj->unk2 = arg1;
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
