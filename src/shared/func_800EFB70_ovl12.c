#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

extern s8 D_800D1C0F;
extern s16 D_8009A1F8[];

void func_800EFB70_ovl12(Obj3DD4* a) {
    if (D_800D1C0F == 0) {
        if (a->unk7C == 0x28) {
            *(s32*)((u8*)a + 0x94) = D_8009A1F8[0x13];
            D_8009A1F8[0x13] = D_8009A1F8[0x12] - 0x10;
        }
        if (--a->unk7C == 0) {
            func_8003D29C(0x14, 0x40);
        }
        if (**(s8**)((u8*)a + 0x80) == 0) {
            play_sound(2, 0x47, a);
            set_animation(a, 0);
            a->unk24 = 0xFFF80000;
            a->unk6++;
        }
    }
}
