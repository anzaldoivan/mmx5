#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#define g_Player_as_X4_Obj (*(X4_Obj*)&g_Player)

extern u8 D_800F9104_ovl29[];
extern Unk800770CC D_800F8FB4_ovl29[];
extern u8 D_800F8FBC_ovl29[];
extern u8 D_800F8FB8_ovl29[];
extern u8 D_80074EE0[];
extern u8 D_800750C0[];

void func_800EECF8_ovl29(ObjEECF8* e) {
    e->unk7C = 0;
    e->unk5C = 6;
    e->unk61 = 0;
    e->unk14 = g_Player_as_X4_Obj.bg_offset;
    e->unk18 = e->x.val;
    e->unk1C = e->y.val;
    if (g_Player_as_X4_Obj.x_pos.val < e->x.val) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
    e->unk30 = D_800F9104_ovl29;
    e->unk16 = 4;
    e->unk68 = D_800F8FB4_ovl29;
    e->unk54 = D_800F8FBC_ovl29;
    e->unk50 = D_800F8FB8_ovl29;
    e->unk67 = 0;
    switch (e->unk2) {
    case 0:
        e->unk58 = D_800750C0;
        set_animation(e, 1);
        e->unk60 = 3;
        e->unk80 = 0;
        e->unk88 = 0;
        e->unk8C = 0x78;
        e->unk5 = 2;
        break;
    case 1:
        e->unk58 = D_80074EE0;
        e->unk80 = 1;
        e->unk60 = 4;
        e->unk88 = 0;
        e->unk8C = 0x78;
        e->unk5 = 5;
        break;
    default:
        e->unk58 = D_80074EE0;
        e->unk60 = 4;
        e->unk80 = 1;
        e->unk88 = 0;
        e->unk8C = 0x78;
        set_animation(e, 5);
        e->unk5 = 8;
        break;
    }
    e->unk20 = 0;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk4 = 1;
    e->unk6 = 0;
}
