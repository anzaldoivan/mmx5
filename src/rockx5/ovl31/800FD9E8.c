#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void set_animation_frame(u8* a0, s32 a1, s32 a2);

extern Tbl800EEB44 D_800FA16C_ovl31;
extern u8 D_8009A0B4;
extern u8 D_800FF870_ovl31[];
extern u8 D_800FF874_ovl31[];
extern u8 D_800750C0[];

void func_800FD9E8_ovl31(u8* obj) {
    u8* par;
    Tbl800EEB44 tbl;
    u8 dir;
    u8 n;
    u16 x;
    u16 d;
    Ent6B44* e = (Ent6B44*)obj;

    par = *(u8**)(obj + 0x80);
    tbl = D_800FA16C_ovl31;
    e->unk40 = *(u16*)(par + 0x40);
    e->unk42 = *(u16*)(par + 0x42) & 0x7FFF;
    e->unk30 = *(void**)(par + 0x30);
    e->unk3C = *(s32*)(par + 0x3C);
    e->unk14 = D_8009A0B4;
    e->unk16 = 4;
    dir = par[0x15];
    e->unk67 = 0;
    e->unk3 = 0;
    e->unk68 = 0;
    e->unk50 = (s32)D_800FF870_ovl31;
    e->unk54 = (s32)D_800FF874_ovl31;
    e->unk58 = (s32)D_800750C0;
    obj[0x62] = 0;
    obj[0x61] = 0;
    obj[0x15] = dir;
    n = par[0x7];
    par[0x7] = n + 1;
    obj[0x7] = n;
    if (obj[0x15] == 0) {
        *(s16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x80) + 0xA) - 0x30;
    } else {
        *(s16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x80) + 0xA) + 0x30;
    }
    x = *(u16*)(*(u8**)(obj + 0x80) + 0xE);
    *(s32*)(obj + 0x24) = 0x8000;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    d = tbl.v[*(s8*)(obj + 0x7)];
    obj[0x5C] = 3;
    obj[0x60] = 3;
    obj[0x90] = 0;
    *(s16*)(obj + 0x7C) = 0;
    *(s16*)(obj + 0x7E) = 0;
    *(s16*)(obj + 0xE) = x + d;
    set_animation_frame(obj, 0xD, random_byte() % 10);
    play_sound(2, 0xE, obj);
    obj[0x5] = 0;
    obj[0x4]++;
}

#define func_800F6BB8_ovl03 func_800FDBA4_ovl31
#define D_800F9E70_ovl03 D_800FF870_ovl31
#define D_800F9E74_ovl03 D_800FF874_ovl31
#define func_800F6D9C_ovl03 func_800FDD88_ovl31
#define func_800F6EE4_ovl03 func_800FDED0_ovl31
#include "shared/func_800F6BB8_ovl03.c"
#undef func_800F6BB8_ovl03
#undef func_800F6D9C_ovl03
#undef D_800F9E70_ovl03
#undef D_800F9E74_ovl03
#undef func_800F6EE4_ovl03
