#include "types.h"
#include "mmx5/ovl10.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"

void func_800F5994_ovl10(u8* obj) {
    if (*(s16*)(obj + 0x7E) != 0 && *(signed char*)(obj + 2) == 1) {
        *(s16*)(obj + 0x7E) -= 1;
        animate_object(obj);
        return;
    }
    *(s16*)(obj + 0x7C) = 1;
    obj[6] = 1;
}

void func_800F59EC_ovl10(u8* obj) {
    apply_object_motion(obj);
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 2 && *(s32*)(obj + 0x24) <= 0) {
        set_animation(obj, 3);
    }
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) <= 0) {
        if (*(s16*)(obj + 0x7C) != 0) {
            obj[6] = 1;
            *(u16*)(obj + 0x7C) = *(u16*)(obj + 0x7C) - 1;
            if (obj[0x8A] != 0 && *(s8*)(obj + 2) == 0 &&
                *(s32*)(obj + 0x94) == 0) {
                set_animation(obj, 0);
                obj[0x8F] = 0x14;
                *(s16*)(obj + 0x7E) = 0x14;
            }
        } else {
            obj[6] = 3;
            set_animation(obj, 0);
            *(s16*)(obj + 0x7C) = 0x3C;
        }
    }
}

extern void func_800F6250_ovl10(void*);

void func_800F5AE0_ovl10(u8* obj) {
    u8 v;

    func_800F6250_ovl10(obj);
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0);
        if (*(signed char*)(obj + 2) != 0) {
            v = 6;
        } else if (obj[0x8E] != 0) {
            obj[0x8E] = 0;
            obj[0x88] = 0;
            obj[5] = D_800FBE00_ovl10.u[(obj[0x8A] * 2 + obj[0x89]) * 5];
            goto end;
        } else {
            v = D_800FBE00_ovl10
                    .u[++obj[0x88] + (obj[0x8A] * 2 + obj[0x89]) * 5];
        }
        obj[5] = v;
    end:
        obj[6] = 0;
    }
}
