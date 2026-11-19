#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F9254_ovl00(u8* obj) {
    u8* child;
    s32 t;

    t = *(u16*)(obj + 0x7C) - 1;
    *(u16*)(obj + 0x7C) = t;
    if ((t << 16) == 0) {
        if (*(s16*)(obj + 0x7E) != 0) {
            set_animation(obj, 3);
            obj[6]++;
        } else {
            child = func_8002D1A4();
            if (child != 0) {
                child[0] = 0x61;
                child[1] = 3;
                child[2] = 2;
                *(u8**)(child + 0x7C) = obj;
            }
        }
        *(s16*)(obj + 0x7C) = 3;
    }
    if (*(s16*)(obj + 0x7E) == 0) {
        if (*(s16*)(obj + 0xA) < 0x11E9) {
            *(s16*)(obj + 0x7C) = 0x78;
            *(s16*)(obj + 0x7E) = 1;
        } else {
            *(s16*)(obj + 0xA) = *(u16*)(obj + 0xA) - 1;
        }
        *(s32*)(obj + 0xC) += 0x8000;
        if (*(s16*)(obj + 0xE) >= 0x130) {
            *(s16*)(obj + 0xE) = 0x130;
        }
    }
    animate_object(obj);
    apply_object_motion(obj);
}
