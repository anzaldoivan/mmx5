#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800EFA5C_ovl18(u8* obj) {
    u8* parent;

    animate_object(obj);
    parent = *(u8**)(obj + 0x50);
    if (((s8*)parent)[6] >= 2) {
        if (((s8*)obj)[2] == 0) {
            if (((s8*)parent)[2] == 10) {
                set_animation(obj, 10);
            } else {
                set_animation(obj, 5);
            }
            obj[5]++;
        } else {
            obj[4]++;
        }
    }
}

void func_800EFAF8_ovl18(u8* o) {
    animate_object(o);
    if (*(s8*)(o + 0x46) == 0) {
        o[0x16] = 1;
        set_animation(o, 3);
        o[5]++;
    }
}

extern u8* find_free_visual_obj(void);

void func_800EFB4C_ovl18(u8* obj) {
    u8* child;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        child = find_free_visual_obj();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x18;
            child[2] = 3;
            child[0x16] = 0;
            child[0x15] = 0;
            child[0x14] = obj[0x14];
            *(s16*)(child + 0xA) = *(s16*)(obj + 0xA);
            *(s16*)(child + 0xE) = *(s16*)(obj + 0xE);
            *(s16*)(child + 0x42) = *(s16*)(obj + 0x42);
            *(s16*)(child + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
        }
        obj[5]++;
    }
}

extern s8 D_8009A424;

void func_800EFC14_ovl18(u8* obj) {
    if (D_8009A424 == 0) {
        animate_object(obj);
        if (*(s8*)(obj + 0x46) == 0) {
            obj[4]++;
        }
    }
}
