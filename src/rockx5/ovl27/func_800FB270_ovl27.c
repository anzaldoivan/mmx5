#include "types.h"

extern ObjFAF38* func_8002D210();

void func_800FB270_ovl27(ObjFAF38* arg0, u8 arg1) {
    ObjFAF38* obj = func_8002D210();

    if (obj != 0) {
        obj->unk0 = 0x41;
        obj->unk1 = 0x19;
        obj->unk2 = arg1;
        *(s32*)&obj->unk8 = 0;
        *(s32*)&obj->unkC = 0;
        obj->unk7C = arg0;
        obj->unk42 = arg0->unk42 & 0x7FFF;
        obj->unk30 = arg0->unk30;
        obj->unk3C = arg0->unk3C;
        obj->unk40 = arg0->unk40;
        obj->unk14 = arg0->unk14;
    }
}
