#include "types.h"

typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[2];
    s32 unk8;
    s32 unkC;
    u8 pad10[0x44];
    s16 unk54;
    u8 pad56[6];
    Unk80022FF0Src* unk5C;
} Unk800F7360Obj;

void func_800F7360_ovl28(Unk800F7360Obj* obj, Unk800F7360Arg* arg) {
    if (obj->unk54 != 0) {
        obj->unk54--;
    } else {
        obj->unk54 = 3;
        obj->unk8 = obj->unk5C->unk18;
        obj->unkC = obj->unk5C->unk1C;
    }
    if (arg->unk9A < 0) {
        obj->unk5++;
    }
}
