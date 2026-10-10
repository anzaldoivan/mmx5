#include "types.h"

typedef struct {
    u8 pad0[6];
    u8 unk6;
    u8 pad7;
    s32 unk8;
    s32 unkC;
    u8 pad10[0x44];
    s16 unk54;
    u8 pad56[6];
    Unk80022FF0Src* unk5C;
} Unk800FC2E8Obj;

void func_800FC2E8_ovl06(Unk800FC2E8Obj* obj, Unk800F7360Arg* arg) {
    if (obj->unk54 != 0) {
        obj->unk54--;
    } else {
        obj->unk54 = 10;
        obj->unk8 = obj->unk5C->unk18;
        obj->unkC = obj->unk5C->unk1C;
    }
    if (arg->unk9A < 0) {
        obj->unk6++;
    }
}
