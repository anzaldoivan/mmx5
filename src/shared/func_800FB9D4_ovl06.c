#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800FB9D4_ovl06(u8* arg0) {
    if ((*(u8**)(arg0 + 0x7C))[0x8A] != 0) {
        arg0[6]++;
    }
}

void func_800FBA04_ovl06(ObjFBA04* obj) {
    if (obj->timer == 0) {
        set_animation(obj, 0x12);
        play_sound(2, 0x18, obj);
        obj->state++;
        obj->unk60 = 6;
        return;
    }
    obj->timer--;
}

extern u8 D_800FF6AC_ovl06[];
extern u8 D_800FF6B0_ovl06[];

void func_800FBA68_ovl06(Obj800FBA68* obj) {
    switch (obj->unk47) {
    case 0x4E:
        obj->unk50 = D_800FF6AC_ovl06;
        break;
    case 0x51:
        obj->unk50 = D_800FF6B0_ovl06;
        break;
    case 0x53:
        obj->unk50 = 0;
        break;
    }
    if (obj->unk45 == 1) {
        obj->unk7C->unk8B = obj->unk2 & 0xF;
        obj->unk4 = 2;
    }
}
