#include "types.h"
#include "mmx5/globals.h"

void func_800EFD08_ovl03(ObjEFD08* arg0) {
    ObjEFD08* obj;

    obj = func_8002D1A4();
    if (obj != 0) {
        obj->unk0 = 0x41;
        obj->unk1 = 7;
        obj->unk2 = 0;
        obj->unk40 = arg0->unk40;
        obj->unk42 = arg0->unk42;
        obj->unk30 = arg0->unk30;
        obj->unk3C = arg0->unk3C;
        obj->unk14 = arg0->unk14;
        obj->unk15 = arg0->unk15;
        obj->unk8 = arg0->unk8;
        obj->unkC = arg0->unkC;
        obj->unk7C = arg0;
        obj->unk16 = 6;
    }
}
