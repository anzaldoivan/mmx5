#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/sound.h"

#define g_Player_as_Ent3CC_Src (*(Ent3CC_Src*)&g_Player)

#define SCR ((X5Scr*)D_1F80004C.bytes)

extern s32 func_8002B5B4(s32);
extern void func_800F0D34_ovl00(X5Ent*);
extern u8 D_800750C0[];
extern u8 D_800FA82C_ovl00[];
extern u8 D_80074EE0[];
extern u8 D_800FA758_ovl00[];
extern u8 D_800FA75C_ovl00[];
extern u8 D_800FA760_ovl00[];
extern u8 D_800FA764_ovl00[];
extern u8 D_800FA768_ovl00[];
extern u8 D_800FA76C_ovl00[];
extern u8 D_800FA770_ovl00[];
extern u8 D_800FA774_ovl00[];
extern u8 D_800FA778_ovl00[];
extern u8 D_800FA77C_ovl00[];
extern u8 D_800FA784_ovl00[];

void func_800EECA4_ovl00(X5Ent* a) {

    a->f5C = 4;
    a->f61 = 0;
    a->f58 = D_800750C0;
    a->f14 = g_Player_as_Ent3CC_Src.unk14;
    a->f20 = 0;
    a->f24 = 0;
    a->f28 = 0;
    a->f2C = 0;
    a->f30 = D_800FA82C_ovl00;
    a->f67 = 1;
    a->f70 = 0;
    a->f18 = a->f8;
    a->f1C = a->fC;
    SCR->f93 = 0;
    SCR->f87 = 0;
    SCR->f85 = 0;
    SCR->f91 = 0;
    SCR->f88 = 0;
    SCR->f96 = 0;

    switch (a->f2) {
    case 0:
        a->f54 = D_800FA758_ovl00;
        a->f50 = D_800FA768_ovl00;
        a->f68 = D_800FA778_ovl00;
        a->f16 = 4;
        a->f60 = 3;
        a->f15 = (a->f8 <= g_Player_as_Ent3CC_Src.x) << 6;
        set_animation(a, 0);
        SCR->f94 = 3;
        SCR->f92 = 0x32;
        a->f4 = 1;
        a->f5 = 4;
        func_800F0D34_ovl00(a);
        break;
    case 1:
        a->f42 = ((func_8002B5B4(a->f1) * 4 + 0x19) % 16) |
                 (((func_8002B5B4(a->f1) + 6) / 4 + 0x1E0) << 6);
        a->f58 = D_80074EE0;
        a->f54 = D_800FA758_ovl00;
        a->f50 = D_800FA768_ovl00;
        a->f68 = 0;
        a->f16 = 4;
        a->f60 = 3;
        a->f15 = (a->f8 <= g_Player_as_Ent3CC_Src.x) << 6;
        set_animation(a, 0xC);
        SCR->f94 = 3;
        SCR->f92 = 0x32;
        a->f4 = 1;
        a->f5 = 4;
        func_800F0D34_ovl00(a);
        break;
    case 2:
        a->f42 = ((func_8002B5B4(a->f1) * 4 + 0x19) % 16) |
                 (((func_8002B5B4(a->f1) + 6) / 4 + 0x1E0) << 6);
        a->f58 = D_80074EE0;
        a->f54 = D_800FA760_ovl00;
        a->f50 = D_800FA770_ovl00;
        a->f68 = 0;
        a->f16 = 4;
        a->f60 = 3;
        a->f15 = 0;
        set_animation(a, 5);
        SCR->f94 = 3;
        SCR->f92 = 0x32;
        a->f4 = 1;
        a->f5 = 4;
        func_800F0D34_ovl00(a);
        break;
    case 3:
        a->f42 = ((func_8002B5B4(a->f1) * 4 + 0x19) % 16) |
                 (((func_8002B5B4(a->f1) + 6) / 4 + 0x1E0) << 6);
        a->f58 = D_80074EE0;
        a->f54 = D_800FA760_ovl00;
        a->f50 = D_800FA770_ovl00;
        a->f68 = 0;
        a->f16 = 4;
        a->f60 = 3;
        a->f15 = 0x40;
        set_animation(a, 5);
        SCR->f94 = 3;
        SCR->f92 = 0x32;
        a->f4 = 1;
        a->f5 = 4;
        func_800F0D34_ovl00(a);
        break;
    case 16:
        a->f16 = 5;
        a->f60 = 4;
        a->f15 = 0;
        if (SCR->f84 != 0) {
            switch (SCR->sub->unk2) {
            case 0:
                a->f54 = D_800FA75C_ovl00;
                a->f50 = D_800FA76C_ovl00;
                a->f68 = D_800FA77C_ovl00;
                set_animation(a, 0xF);
                a->f15 = 0;
                a->f5 = 3;
                break;
            case 1:
                a->f54 = D_800FA75C_ovl00;
                a->f50 = D_800FA76C_ovl00;
                a->f68 = D_800FA77C_ovl00;
                set_animation(a, 0xD);
                a->f15 = 0;
                a->f58 = D_80074EE0;
                a->f5 = 2;
                break;
            case 2:
                a->f54 = D_800FA764_ovl00;
                a->f50 = D_800FA774_ovl00;
                a->f68 = D_800FA784_ovl00;
                set_animation(a, 6);
                a->f15 = 0;
                a->f58 = D_80074EE0;
                a->f5 = 2;
                break;
            case 3:
                a->f54 = D_800FA764_ovl00;
                a->f50 = D_800FA774_ovl00;
                a->f68 = D_800FA784_ovl00;
                set_animation(a, 6);
                a->f15 = 0x40;
                a->f58 = D_80074EE0;
                a->f5 = 2;
                break;
            }
        } else {
            a->f4 = 5;
            return;
        }
        SCR->f90 = 0;
        a->f4 = 2;
        break;
    default:
        break;
    }
    a->f6 = 0;
}
#undef g_Player_as_Ent3CC_Src
#undef SCR

#define func_800F0740_ovl27 func_800EF91C_ovl00
#define func_800F0408_ovl27 func_800EF5E4_ovl00
#include "shared/func_800EF204_ovl00.c"
#undef func_800F0408_ovl27
#undef func_800F0740_ovl27
