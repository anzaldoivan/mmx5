#include "types.h"

typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[2];
    s32 unk8;
    s32 unkC;
    u8 pad10[0x40];
    Unk80022FF0Src* unk50;
    s16 unk54;
} Unk80022FF0Obj;

typedef struct {
    u8 pad0[0x8C];
    signed char unk8C;
} Unk80022FF0Arg;

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
