#include "types.h"

void func_80022FF0(Unk80022FF0Obj* obj, Unk80022FF0Arg* arg) {
    if (obj->unk54 != 0) {
        obj->unk54--;
    } else {
        obj->unk54 = 3;
        obj->unk8 = obj->unk50->unk18;
        obj->unkC = obj->unk50->unk1C;
    }
    if (arg->unk8C < 0) {
        obj->unk5++;
    }
}
