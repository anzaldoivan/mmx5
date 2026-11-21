#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800F6A8C_ovl28(u8* obj);

void func_800F5DE4_ovl28(u8* obj) {
    func_800F6A8C_ovl28(obj);
    animate_object(obj);
    if (((s8*)obj)[7] == 2) {
        obj[7] = 3;
        set_animation(obj, 7);
        obj[6]++;
    }
}

extern u8* find_free_visual_obj(void);

void func_800F5E40_ovl28(u8* obj) {
    s8 kind;
    u8 dir;
    u8* p;

    animate_object(obj);
    kind = *(s8*)(obj + 0x45);
    if (kind == 2) {
        p = find_free_visual_obj();
        if (p != 0) {
            p[0] = 0x61;
            p[1] = 0xB;
            p[2] = kind;
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            dir = obj[0x15];
            p[0x15] = dir;
            if (dir == 0) {
                *(u16*)(p + 0xA) = *(u16*)(obj + 0xA) - 0x14;
            } else {
                *(u16*)(p + 0xA) = *(u16*)(obj + 0xA) + 0x14;
            }
            *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
            *(u8**)(p + 0x50) = obj;
        }
        obj[6]++;
    }
}

void func_800F5F1C_ovl28(u8* obj) {
    animate_object(obj);
    obj[6]++;
}

extern u8 D_800FE198_ovl28[][3];

#define G D_1F80004C.bytes
void func_800F5F4C_ovl28(u8* obj) {
    animate_object(obj);
    if ((signed char)obj[0x45] == 1) {
        obj[5] = D_800FE198_ovl28[0][++G[0x8A] + G[0x89] * 3];
        obj[6] = 0;
        obj[7] = 0;
    }
}
#undef G

#define D_8007BD4C D_800FE268_ovl28

#define func_800532E0 func_800F5FCC_ovl28
#include "shared/func_800532E0.c"
#undef func_800532E0
