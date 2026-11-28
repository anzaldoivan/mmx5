#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

extern u8* find_free_visual_obj(void);
extern u8 D_80075F20[];
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_800F9D0C_ovl11[];
extern u8 D_800F9D10_ovl11[];
extern u8 D_800F9D14_ovl11[];
extern u8 D_800F9EB0_ovl11[];
extern s16 D_800FA054_ovl11;
extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;
extern s16 D_800FA05A_ovl11;
extern s16 D_800FA05C_ovl11;
extern s16 D_800FA05E_ovl11;
extern s16 D_800FA060_ovl11;

void func_800F4FCC_ovl11(u8* arg0) {
    u8* p;
    u8* child;
    u8* prev;
    s32 i;
    u8 b;

    D_800FA054_ovl11 = 0x1240;
    D_800FA056_ovl11 = 0x10D8;
    D_800FA058_ovl11 = 0x1218;
    D_800FA05A_ovl11 = 0x1178;
    D_800FA05C_ovl11 = 0x1A0;
    D_800FA05E_ovl11 = 0x210;
    D_800FA060_ovl11 = 0xB0;
    D_1F80004C.bytes[0x8C] = 0x38;
    arg0[0x5C] = 0;
    D_1F80004C.bytes[0x8D] = 0;
    arg0[0x60] = 4;
    arg0[0x62] = 0;
    if (D_800D1C0C.s != 0xC) {
        ((u16*)arg0)[0x20] = (*D_80098118 >> 7) + 0xB0;
    } else {
        ((u16*)arg0)[0x20] = (*D_80098118 >> 7) + 0x210;
        p = D_1F80009C;
        ((u8**)arg0)[0xF] = p + *(s32*)p;
        ((u16*)arg0)[0x21] = 0x7CC8;
        D_800FA054_ovl11 -= 0x200;
        D_800FA056_ovl11 -= 0x200;
        D_800FA058_ovl11 -= 0x200;
        D_800FA05A_ovl11 -= 0x200;
        D_800FA05C_ovl11 -= 0xE0;
        D_800FA05E_ovl11 -= 0xE0;
        D_800FA060_ovl11 -= 0xE0;
    }
    b = D_8009A0B4;
    arg0[0x16] = 5;
    ((u8**)arg0)[0x15] = D_800F9D10_ovl11;
    ((u8**)arg0)[0x14] = D_800F9D14_ovl11;
    arg0[0x15] = 0;
    arg0[0x3] = 0;
    ((u8**)arg0)[0x1A] = D_800F9D0C_ovl11;
    ((u8**)arg0)[0x16] = D_80075F20;
    arg0[0x61] = 0;
    arg0[0x14] = b;
    func_8003D29C(0x14, 0x40, b);
    i = 0;
    ((s32*)arg0)[0x8] = 0;
    ((s32*)arg0)[0x9] = 0;
    ((s32*)arg0)[0xA] = 0;
    ((s32*)arg0)[0xB] = 0;
    ((u16*)arg0)[0x5] = D_800FA054_ovl11;
    ((u16*)arg0)[0x7] = D_800FA060_ovl11;
    ((u8**)arg0)[0xC] = D_800F9EB0_ovl11;
    ((s32*)arg0)[0x6] = ((s32*)arg0)[0x2];
    ((s32*)arg0)[0x7] = ((s32*)arg0)[0x3];
    D_1F80004C.bytes[0x8B] = 0;
    D_1F80004C.bytes[0x8E] = 0;
    D_1F80004C.bytes[0x8F] = 0;
    D_1F80004C.bytes[0x92] = 0;
    set_animation(arg0, 0xC);
    arg0[0x4] = 1;
    arg0[0x5] = 2;
    arg0[0x6] = 0;
    arg0[0x7] = 0;
    do {
        child = find_free_visual_obj();
        if (child != 0) {
            child[0x0] = 0x51;
            child[0x1] = 0x17;
            child[0x2] = i;
            child[0x14] = arg0[0x14];
            ((s32*)child)[0xE] = ((s32*)arg0)[0xE];
            ((u8**)child)[0xF] = ((u8**)arg0)[0xF];
            ((u16*)child)[0x20] = ((u16*)arg0)[0x20];
            ((u16*)child)[0x21] = ((u16*)arg0)[0x21];
            child[0x16] = 6;
            ((u8**)child)[0x14] = arg0;
            if (i != 0) {
                ((u8**)child)[0x17] = prev;
            } else {
                ((u8**)child)[0x17] = arg0;
            }
            prev = child;
        }
        i++;
    } while (i < 3);
    arg0[0x9A] = 0;
}

#include "shared/func_800F52D4_ovl11.c"

#include "shared/func_800F54A8_ovl11.c"

#include "shared/func_800F55B4_ovl11.c"

#include "shared/func_800F56E8_ovl11.c"

#include "shared/func_800F583C_ovl11.c"

#include "shared/func_800F5958_ovl11.c"

extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void func_800F5B3C_ovl11(u8* obj) {
    s32 v;
    s16 x;
    s16 y;
    u8 st;

    animate_object(obj);
    apply_object_motion(obj);
    x = *(s16*)(obj + 0xA);
    if (x <= D_800FA056_ovl11 - 0x18) {
        *(s16*)(obj + 0xA) = D_800FA056_ovl11 - 0x18;
    } else if (x >= D_800FA058_ovl11 + 0x18) {
        *(s16*)(obj + 0xA) = D_800FA058_ovl11 + 0x18;
    }
    if (obj[0x15] == 0) {
        y = *(s16*)(obj + 0xA);
        if (y < D_8009A0AA - 2 || y <= D_800FA056_ovl11 - 0x18 ||
            D_1F80004C.bytes[0x90] == 1) {
            st = obj[6];
            v = 0xFFFC0000;
            *(s32*)(obj + 0x20) = v;
            *(s32*)(obj + 0x24) = v;
            *(s32*)(obj + 0x28) = 0;
            *(s16*)(obj + 0x7C) = 0x14;
            obj[6] = st + 1;
        }
    } else {
        x = *(s16*)(obj + 0xA);
        if (x > D_8009A0AA + 2 || x >= D_800FA058_ovl11 + 0x18 ||
            D_1F80004C.bytes[0x90] == 1) {
            st = obj[6];
            v = 0x40000;
            *(s32*)(obj + 0x20) = v;
            v = 0xFFFC0000;
            *(s32*)(obj + 0x24) = v;
            *(s32*)(obj + 0x28) = 0;
            *(s16*)(obj + 0x7C) = 0x14;
            obj[6] = st + 1;
        }
    }
}
