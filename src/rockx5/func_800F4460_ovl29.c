#include "types.h"

typedef struct Ovl29Obj {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x8D - 7];
    u8 unk8D;
    u8 unk8E;
    u8 unk8F;
} Ovl29Obj;

extern u8 D_800FA2E0_ovl29[][6];

void func_800F4460_ovl29(Ovl29Obj* obj) {
    if (obj->unk8F == 0) {
        obj->unk5 = D_800FA2E0_ovl29[obj->unk8D][obj->unk8E];
        obj->unk6 = 0;
        obj->unk8E++;
    } else {
        obj->unk8F--;
    }
}
