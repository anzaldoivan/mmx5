#include "types.h"

void func_80023368(Obj23368* arg0, Obj23368* arg1) {
    s8 temp_v0;
    s32 temp;

    temp_v0 = arg1->unk8C;
    if (temp_v0 != 0) {
        if (temp_v0 > 0) {
            arg0->unk3 = 1;
            arg0->unk54 = 3;
            arg0->unk56 = 8;
            arg0->unk58 = (5 - arg0->unk2) * 2;
            arg0->unk8 = arg1->unk8;
            temp = arg1->unkC;
            arg0->unk4 = 1;
            arg0->unk5 = 0;
            arg0->unkC = temp;
            return;
        }
        arg1->unk8C = 0;
    }
}
