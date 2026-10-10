#include "types.h"

typedef struct Ovl12Obj {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x85 - 7];
    u8 unk85;
    u8 unk86;
    u8 unk87;
} Ovl12Obj;

extern u8 D_800F1F94_ovl12[][6];

void func_800EFE34_ovl12(Ovl12Obj* obj) {
    if (obj->unk85 == 0) {
        obj->unk5 = D_800F1F94_ovl12[obj->unk86][obj->unk87];
        obj->unk6 = 0;
        obj->unk87++;
    } else {
        obj->unk85--;
    }
}
