#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"
#include "mmx5/system.h"
#include "mmx5/movement.h"
#include "mmx5/sound.h"

#include "shared/func_800EE9A8_ovl12.c"

extern Tbl800EE974 D_800EE974_ovl12;
extern u8 D_800F1F94_ovl12[][6];

void func_800EF124_ovl12(u8* obj) {
    Tbl800EE974 t = D_800EE974_ovl12;
    u8* p;
    s32 i;

    if (((s8*)obj)[0x45] == 4) {
        obj[0x45] = 0;
        play_sound(2, 0x44, obj);
    }
    if (((s8*)obj)[0x45] == 5) {
        obj[0x45] = 0;
        play_sound(2, 0x3A, obj);
    }
    if (((s8*)obj)[0x45] == 6) {
        obj[0x45] = 0;
        play_sound(2, 0x3B, obj);
    }
    if (((s8*)obj)[0x45] == 7) {
        obj[0x45] = 0;
        play_sound(2, 0x3C, obj);
    }
    if (((s8*)obj)[0x45] == 8) {
        obj[0x45] = 0;
        play_sound(2, 0x45, obj);
    }
    if (((s8*)obj)[0x45] == 1) {
        obj[0x45] = 0;
        play_sound(2, 0x46, obj);
        for (i = 0; i < 5; i++) {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x18;
                p[2] = 4;
                *(u8**)(p + 0x7C) = obj;
                *(s16*)(p + 0xA) = t.a[0][i];
                *(s32*)(p + 0x90) = i;
            }
        }
    }
    if (((s8*)obj)[0x45] == 2) {
        obj[0x45] = 0;
        play_sound(2, 0x46, obj);
        for (i = 0; i < 5; i++) {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x18;
                p[2] = 4;
                *(u8**)(p + 0x7C) = obj;
                if (obj[0x15] == 0) {
                    *(s16*)(p + 0xA) = t.a[1][i];
                } else {
                    *(s16*)(p + 0xA) = t.a[2][i];
                }
                *(s32*)(p + 0x90) = i;
            }
        }
    }
    if (((s8*)obj)[0x45] == 3) {
        obj[0x45] = 0;
        play_sound(2, 0x46, obj);
        for (i = 0; i < 5; i++) {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x18;
                p[2] = 4;
                *(u8**)(p + 0x7C) = obj;
                if (obj[0x15] == 0) {
                    *(s16*)(p + 0xA) = t.a[2][i];
                } else {
                    *(s16*)(p + 0xA) = t.a[1][i];
                }
                *(s32*)(p + 0x90) = i;
            }
        }
    }
    if (((s8*)obj)[0x46] == 0) {
        set_animation(obj, 1);
        obj[5] = D_800F1F94_ovl12[obj[0x86]][obj[0x87]++];
        obj[6] = 0;
    }
}
