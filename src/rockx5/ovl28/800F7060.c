#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F7060_ovl28(u8* a0) {
    move_object(a0);
    if (*(s16*)(a0 + 0xE) >= 0x2FE) {
        *(s16*)(a0 + 0xE) = 0x2FE;
        play_sound(2, 0x6E, a0);
        a0[6]++;
        if (*(s8*)(a0 + 2) != 0) {
            (*(u8**)(a0 + 0x50))[7] = 1;
        }
    }
}

void func_800F70CC_ovl28(u8* obj) {
    animate_object(obj);
    if ((*(s8**)(obj + 0x50))[7] == 2) {
        *(s32*)(obj + 0x24) = 0x80000;
        set_animation(obj, 0x16);
        play_sound(2, 0x75, obj);
        obj[6]++;
    }
}

void func_800F7138_ovl28(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        move_object(obj);
    }
}

void func_800F7174_ovl28(u8* obj) {
    u8* parent;

    animate_object(obj);
    parent = *(u8**)(obj + 0x50);
    if (parent[0x15] == 0) {
        *(s16*)(obj + 0xA) = *(s16*)(parent + 0xA) + 0x30;
    } else {
        *(s16*)(obj + 0xA) = *(s16*)(parent + 0xA) - 0x30;
    }
    *(s16*)(obj + 0xE) = *(s16*)(parent + 0xE) + 0x10;
    if (*(s8*)(obj + 0x45) == 1) {
        obj[4]++;
    }
}

void func_800F71F8_ovl28(u8* p) {
    animate_object(p);
    if (*(s8*)(*(u8**)(p + 0x50) + 6) == 2) {
        p[4]++;
    }
}

#include "shared/func_800F7244_ovl28.c"
