#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

static inline u8 func_800FD4A8_ovl36_check(u8* obj) {
    u8* d = g_Player;

    if (((s8*)d)[0xCA] == 0) {
        if (func_800317B8(obj) == 0) {
            return 0;
        }
        if (((s8*)d)[0xCA] != 0) {
            return 1;
        }
    }
    return 0;
}

void func_800FD4A8_ovl36(u8* obj) {
    u8* parent = *(u8**)(obj + 0x7C);
    u8* child;
    u8* d;

    switch (parent[0x47]) {
    case 0x9E:
    case 0xA2:
        play_sound(2, 0x2A, obj);
        obj[0x8C] = 8;
        obj[0x8D] = 2;
        obj[0x8E] = 0x30;
        obj[0x8F] = 4;
        set_animation(obj, 0x18);
        break;
    case 0xA1:
    case 0xA3:
        ((s8*)obj)[0x8C] = -0x10;
        obj[0x8D] = 2;
        obj[0x8E] = 0x50;
        obj[0x8F] = 4;
        set_animation(obj, 0x18);
        break;
    case 0x76:
    case 0x7F:
        ((s8*)obj)[0x8C] = -0x60;
        obj[0x8D] = 2;
        ((s8*)obj)[0x8E] = -0x60;
        obj[0x8F] = 4;
        set_animation(obj, 4);
        break;
    default:
        obj[3] = 0;
        obj[4] = 2;
        return;
    }
    *(u8**)(obj + 0x50) = obj + 0x8C;

    if (func_800FD4A8_ovl36_check(obj) == 0) {
        return;
    }
    parent[7] = 2;
    obj[5] = 1;
    child = func_8002D1A4();
    if (child != 0) {
        child[0] = 0x41;
        child[1] = 0x27;
        child[2] = 5;
        child[4] = 0xE;
        *(s32*)(child + 0x24) = 0;
        child[0x15] = g_Player[0x15];
        *(s32*)(child + 8) = *(s32*)(g_Player + 8);
        *(s32*)(child + 0xC) = *(s32*)(obj + 0xC);
        *(u16*)(child + 0x40) = *(u16*)(parent + 0x40);
        *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
        *(s32*)(child + 0x30) = *(s32*)(parent + 0x30);
        *(s32*)(child + 0x3C) = *(s32*)(parent + 0x3C);
        child[0x14] = obj[0x14];
        *(u8**)(child + 0x7C) = obj;
    }
    d = g_Player;
    *(s32*)(d + 0xC) = *(s32*)(child + 0xC);
}

#define func_800F64E4_ovl10 func_800FD6B0_ovl36
#define D_800FBF38_ovl10 D_800FEE00_ovl36
#define func_800F660C_ovl10 func_800FD7D8_ovl36
#define func_800F6780_ovl10 func_800FD94C_ovl36
#define func_800F6924_ovl10 func_800FDAF0_ovl36
#define D_800FBF34_ovl10 D_800FEDFC_ovl36
#define func_800F6AAC_ovl10 func_800FDC78_ovl36
#define D_800FBF3C_ovl10 D_800FEE04_ovl36
#define func_800F6CC8_ovl10 func_800FDE94_ovl36
#define D_800FBF88_ovl10 D_800FEE50_ovl36
#define func_800F6EFC_ovl10 func_800FE0C8_ovl36
#define func_800F6F70_ovl10 func_800FE13C_ovl36
#define D_800FBFCC_ovl10 D_800FEE94_ovl36
#define func_800F6FE0_ovl10 func_800FE1AC_ovl36
#define func_800F70B8_ovl10 func_800FE284_ovl36
#include "shared/func_800F64E4_ovl10.c"
#undef func_800F64E4_ovl10
#undef func_800F660C_ovl10
#undef D_800FBF38_ovl10
#undef func_800F6780_ovl10
#undef func_800F6924_ovl10
#undef func_800F6AAC_ovl10
#undef D_800FBF34_ovl10
#undef func_800F6CC8_ovl10
#undef D_800FBF3C_ovl10
#undef func_800F6EFC_ovl10
#undef D_800FBF88_ovl10
#undef func_800F6F70_ovl10
#undef func_800F6FE0_ovl10
#undef D_800FBFCC_ovl10
#undef func_800F70B8_ovl10

#define D_800EEBA0_ovl00 func_800FE2AC_ovl36
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
