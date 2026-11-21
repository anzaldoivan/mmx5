#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

extern u8 D_800FE198_ovl28[][3];

#define G D_1F80004C.bytes
void func_800F57FC_ovl28(u8* obj) {
    if (D_800FE198_ovl28[G[0x89]][G[0x8A] + 1] == 5) {
        *(s16*)(obj + 0x7E) = 100;
    } else {
        *(s16*)(obj + 0x7E) = 0;
    }
    set_animation(obj, 1);
    animate_object(obj);
    obj[6]++;
}
#undef G

extern u8 D_800FE198_ovl28[][3];
extern s32 D_8009A0A8;
extern void func_800F6A8C_ovl28(u8* obj);
extern s32 player_spawn_dash_spark(void* arg0);

#define G D_1F80004C.bytes
void func_800F5884_ovl28(u8* obj) {
    func_800F6A8C_ovl28(obj);
    if (*(s16*)(obj + 0x7E) != 0) {
        animate_object(obj);
        (*(s16*)(obj + 0x7E))--;
        return;
    }
    play_sound(2, 0x71, obj);
    obj[0x9A] = 1;
    if (D_800FE198_ovl28[G[0x89]][G[0x8A] + 1] == 5) {
        set_animation(obj, 8);
    } else {
        set_animation(obj, 3);
    }
    *(s32*)(obj + 0x28) = -0x3000;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s16*)(obj + 0x7C) = 0x1E;
    if (*(s32*)(obj + 0x8) < D_8009A0A8) {
        *(s32*)(obj + 0x20) = 0x68000;
        obj[0x15] = 0x40;
    } else {
        *(s32*)(obj + 0x20) = 0xFFF98000;
        obj[0x15] = 0;
    }
    player_spawn_dash_spark(obj);
    obj[6]++;
}
#undef G

extern u8 D_800FE198_ovl28[][3];

#define G D_1F80004C.bytes
void func_800F59AC_ovl28(u8* obj) {
    if ((signed char)obj[0x45] == 1) {
        obj[5] = D_800FE198_ovl28[0][++G[0x8A] + G[0x89] * 3];
        obj[6] = 0;
    }
    if (obj[0x15]) {
        *(s32*)(obj + 0x20) = 0x42000;
    } else {
        *(s32*)(obj + 0x20) = -0x42000;
    }
    *(s32*)(obj + 0x28) = -0x3000;
    *(s8*)(obj + 0x9A) = -1;
    obj[6]++;
}
#undef G

extern u8 D_800FE198_ovl28[][3];

#define G D_1F80004C.bytes
void func_800F5A4C_ovl28(u8* obj) {
    s32 m;

    animate_object(obj);
    m = 2;
    if (obj[0x15]) {
        m = 1;
    }
    if (obj[0x70] & m) {
        *(s32*)(obj + 0x20) = 0;
    }
    if (*(s32*)(obj + 0x20) != 0) {
        apply_object_motion(obj);
        if (obj[0x15]) {
            if (*(s32*)(obj + 0x20) < 0) {
                *(s32*)(obj + 0x20) = 0;
            }
        } else if (*(s32*)(obj + 0x20) > 0) {
            *(s32*)(obj + 0x20) = 0;
        }
        if (*(s32*)(obj + 0x20) != 0) {
            return;
        }
    }
    if ((signed char)obj[0x45] == 1) {
        obj[5] = D_800FE198_ovl28[0][++G[0x8A] + G[0x89] * 3];
        obj[6] = 0;
    }
}
#undef G

void func_800F5B58_ovl28(u8* obj) {
    s32 mask;
    u8 dir;

    animate_object(obj);
    apply_object_motion(obj);
    dir = obj[0x15];
    mask = 2;
    if (dir != 0 && (mask = 1, obj[0x15] != 0)) {
        if (*(s32*)(obj + 0x20) < 0x42000) {
            *(s32*)(obj + 0x20) = 0x42000;
        }
    } else if (*(s32*)(obj + 0x20) > -0x42000) {
        *(s32*)(obj + 0x20) = -0x42000;
    }
    if ((obj[0x70] & mask) || (s8)obj[0x45] == 2) {
        set_animation(obj, 0x1A);
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = 0x42000;
        } else {
            *(s32*)(obj + 0x20) = -0x42000;
        }
        *(s32*)(obj + 0x28) = -0x3000;
        *(s8*)(obj + 0x9A) = -1;
        obj[6]++;
        play_sound(2, 0x72, obj);
    }
}

void func_800F5C58_ovl28(u8* o) {
    animate_object(o);
    if (*(s8*)(o + 0x45) == 1) {
        o[5] = 7;
        o[6] = 0;
        o[7] = 0;
    }
}
