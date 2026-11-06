#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800750C0[];
extern s8 D_800D1C26;
extern u8 D_800F95E0_ovl11[];
extern u8 D_800F9614_ovl11[];
extern u8 D_800F961C_ovl11[];

void func_800EF1F0_ovl11(u8* obj) {
    X4_Obj* o = (X4_Obj*)obj;

    o->state = 1;
    o->unk5 = 2;
    o->on_screen = 1;
    o->hp = 8;
    o->unk60 = 4;
    o->animation_table = (u32**)D_800F95E0_ovl11;
    o->unk54 = D_800F961C_ovl11;
    o->unk50 = D_800F9614_ovl11;
    o->unk6 = 0;
    o->unk58 = D_800750C0;
    o->bg_offset = 0;
    o->unk15 = 0;
    o->unk7C = 0;
    obj[0x61] = 0;
    o->unk68 = 0;
    o->unk16 = 5;
    o->unk18 = o->x_pos;
    o->unk1C = o->y_pos;
    func_800171E8(obj, 0);
    if ((u8)(obj[2] - 5) < 2) {
        D_800D1C26 = 0;
    }
    *(s16*)(obj + 0x80) = 0;
    *(s16*)(obj + 0x84) = 0;
}
