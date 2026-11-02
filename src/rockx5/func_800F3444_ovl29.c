#include "types.h"

extern void func_80024548(s32);
extern void func_8003D29C(s32, s32);
extern s16 D_800FA648_ovl29;
extern s16 D_800FA64A_ovl29;
extern s16 D_800FA64C_ovl29;
extern s16 D_800FA64E_ovl29;
extern s16 D_800FA650_ovl29;
extern u8 D_8009A0B4;
extern u8 D_800FA244_ovl29[];
extern u8 D_800F9894_ovl29[];
extern u8 D_80075A20[];
extern u32* D_80098118;
extern u8 D_800D1C00[];

void func_800F3444_ovl29(ObjF3444* obj) {
    u8* p;
    s32 z;
    u8 b;
    u32 t;

    z = 0;
    D_800FA648_ovl29 = 0xD9F;
    D_800FA64A_ovl29 = 0xD17;
    D_800FA64C_ovl29 = 0xC90;
    D_800FA64E_ovl29 = 0x280;
    D_800FA650_ovl29 = 0x260;
    b = D_8009A0B4;
    obj->unk30 = D_800FA244_ovl29;
    obj->unk16 = 5;
    obj->unk50 = D_800F9894_ovl29;
    obj->unk61 = 0;
    obj->unk8A = 0;
    obj->unk62 = 0;
    obj->unk14 = b;
    obj->unk68 = 0;
    obj->unk58 = D_80075A20;
    obj->unk54 = 0;
    t = *D_80098118;
    obj->unkA = 0xD68;
    obj->unkE = 0x1B0;
    obj->unk20 = 0;
    obj->unk24 = 0;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk40 = (t >> 7) + 0x160;
    p = D_800D1C00;
    *(ObjF3444**)(p + 0x20) = obj;
    p[0xA2] = 0x20;
    func_80024548(z);
    obj->unk60 = 4;
    obj->unk5C = 0;
    obj->unk67 = 0;
    obj->unk5 = 2;
    obj->unk4++;
    func_8003D29C(0x14, 0x40);
}
